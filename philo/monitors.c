/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:01:40 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 14:20:32 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

/*
Ensures that if one philosopher dies, all others are properly marked as dead to 
prevent inconsistencies.
*/
static int	find_dying_philo(t_data *data)
{
    int			i;
    int			dying_philo;
    uint64_t	time_since_meal;

    i = 0;
    dying_philo = -1;
    while (i < data->num_philos)
    {
        pthread_mutex_lock(&data->philo[i].mut_last_eat);
        time_since_meal = get_time_ms() - data->philo[i].last_eat;
        pthread_mutex_unlock(&data->philo[i].mut_last_eat);
        if (time_since_meal > data->philo[i].time_to_die)
        {
            dying_philo = i;
            break ;
        }
        i++;
    }
    return (dying_philo);
}

/* modificado para el print / usar version vieja print_msg
void    end_simulation(t_data *data)
{
    int         dying_philo;
    uint64_t    current_time;

    printf("DEBUG: Entering end_simulation(). keep_iterating=%d, dead=0\n", 
        data->keep_iterating);
    pthread_mutex_lock(&data->death_lock);
    if (!data->keep_iterating)
    {
        printf("DEBUG: Simulation already ending\n");
        pthread_mutex_unlock(&data->death_lock);
        return ;
    }
    dying_philo = find_dying_philo(data);
    if (dying_philo >= 0)
        print_msg(&data->philo[dying_philo], DIED);
    data->keep_iterating = 0;
    data->dead = 1;
    printf("DEBUG: Setting simulation end flags\n");
    pthread_mutex_unlock(&data->death_lock);
    printf("DEBUG: end_simulation finished\n");
}*/

//usar version nueva de print_msg
void	end_simulation(t_data *data)
{
    int			dying_philo;
    //uint64_t	current_time;

    printf("DEBUG: Entering end_simulation(). keep_iterating=%d, dead=0\n", 
        data->keep_iterating);
    pthread_mutex_lock(&data->death_lock);
    if (!data->keep_iterating)
    {
        printf("DEBUG: Simulation already ending\n");
        pthread_mutex_unlock(&data->death_lock);
        return ;
    }
    data->keep_iterating = 0;
    data->dead = 1;
    printf("DEBUG: Setting simulation end flags\n");
    dying_philo = find_dying_philo(data);
    if (dying_philo >= 0)
    {
        //current_time = get_time_ms() - data->start_time;
        print_msg(&data->philo[dying_philo], DIED);
        //printf("%lu %d died\n", current_time, dying_philo + 1);
    }
    pthread_mutex_unlock(&data->death_lock);
    printf("DEBUG: end_simulation finished\n");
}

/**
 * Monitors if a philosopher has died.
 * explicitly call end_simulation() when death is detected
 * return NULL when the monitoring stops.
 */
void    *check_death(void *arg)
{
    t_data  *data;
    int     i;

    data = (t_data *)arg;
    if (!data)
        return (NULL);
    printf("DEBUG: Death monitor started\n"); // DEBUG
    while (1)
    {
        pthread_mutex_lock(&data->death_lock);
        if (!data->keep_iterating || data->dead)
        {
            printf("DEBUG: Death monitor ending because keep_iterating=%d, dead=%d\n", 
                   data->keep_iterating, data->dead);//debug
            pthread_mutex_unlock(&data->death_lock);
            break;
        }
        pthread_mutex_unlock(&data->death_lock);
        i = 0;
        while (i < data->num_philos)
        {
            if (has_died(&data->philo[i]))
            {
                printf("DEBUG: Philosopher %d death detected by monitor\n", i + 1);
                end_simulation(data);  // Need to call this here when death is detected
                printf("DEBUG: Returned from end_simulation\n");//debug
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    printf("DEBUG: Death monitor thread ending\n");  // Add this debug print
    return (NULL);
}

void    update_status(t_data *data, t_philo *philo, t_status new_status, int already_locked)
{
    if (!already_locked)
        pthread_mutex_lock(&data->death_lock);
    if (data->dead == 0)
        philo->status = new_status;
    if (!already_locked)
        pthread_mutex_unlock(&data->death_lock);
}

/**
 * Monitors if all philosophers have eaten enough times.
 * Calls end_simulation() when all philosophers have eaten enough
 * return NULL when the monitoring stops.
 */
void    *check_meals(void *arg)
{
    t_data  *data;
    int     i;
    int     full_philos;
    int     should_end;

    data = (t_data *)arg;
    while (1)
    {
        should_end = 0;
        pthread_mutex_lock(&data->death_lock);
        if (!data->keep_iterating || data->dead)
            should_end = 1;
        pthread_mutex_unlock(&data->death_lock);

        if (should_end)
            break;

        full_philos = 0;
        i = 0;
        while (i < data->num_philos)
        {
            pthread_mutex_lock(&data->philo[i].mut_num_meals);
            if (data->philo[i].meals >= data->nb_meals)
                full_philos++;
            else
                i = -1;  // Forces rechecking all philosophers
            pthread_mutex_unlock(&data->philo[i].mut_num_meals);
            i++;
        }
        if (full_philos == data->num_philos)
        {
            end_simulation(data);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}
 
/* THIS VERSION NEEDS CHANGES BECAUSE DEATH MESSAGE IS NOT BEING PROPERLY PRINTED
void	end_simulation(t_data *data)
{
	int	i;
    int dying_philo = -1;  // Track which philosopher triggered death

	i = 0;
    printf("DEBUG: Entering end_simulation(). keep_iterating=%d, dead=%d\n", 
        data->keep_iterating, data->dead); // DEBUG
    pthread_mutex_lock(&data->death_lock);
    if (!data->keep_iterating)
    {
        printf("DEBUG: simulation already ending\n");  // Add this debug print
        pthread_mutex_unlock(&data->death_lock);
        return;
    }
	data->keep_iterating = 0;
    data->dead = 1;
    printf("DEBUG: Setting simulation end flags\n"); // DEBUG
	while (i < data->num_philos)
	{
        printf("DEBUG: Marking philosopher %d as dead\n", i + 1);//debug
		update_status(data, &data->philo[i], dead, 1);
		i++;
	}
    if (dying_philo >= 0 && dying_philo < data->num_philos)
    {
        printf("DEBUG: Printing death message for philosopher %d\n", dying_philo + 1);
        print_msg(&data->philo[dying_philo], DIED);
    }
	pthread_mutex_unlock(&data->death_lock);
    printf("DEBUG: end_simulation finished\n");  //debug 
}*/