/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:01:40 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 11:24:09 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

/*
Ensures that if one philosopher dies, all others are properly marked as dead to 
prevent inconsistencies.
*/
void	end_simulation(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->death_lock);
    if (!data->keep_iterating)  // If already ended, don't do it again
    {
        pthread_mutex_unlock(&data->death_lock);
        return;
    }
	data->keep_iterating = 0;
    data->dead = 1;
	while (i < data->num_philos)
	{
		update_status(data, &data->philo[i], dead, 1);
		i++;
	}
	pthread_mutex_unlock(&data->death_lock);
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

/**
 * Monitors if a philosopher has died.
 * explicitly call end_simulation() when death is detected
 * return NULL when the monitoring stops.
 */
void    *check_death(void *arg)
{
    t_data  *data;
    int     i;
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
        i = 0;
        while (i < data->num_philos)
        {
            if (has_died(&data->philo[i]))
            {
                end_simulation(data);  // Need to call this here when death is detected
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    return (NULL);
}
 
/*void	*check_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (check_keep_iterating(data))
	{
		i = 0;
		while (i < data->num_philos)
		{
			if (has_died(&data->philo[i])) // ✅ Checks if a philosopher died
			{
				end_simulation(data); // ✅ Marks all as dead and stops simulation
				return (NULL);
			}
			i++;
		}
		usleep(1000); // ✅ Prevents excessive CPU usage
	}
	return (NULL);
}*/

/*
void	*check_meals(void *arg)
{
	t_data	*data;
	int		i;
	int		full_philos;

	data = (t_data *)arg;
	while (check_keep_iterating(data) && data->nb_meals > 0)
	{
		full_philos = 0;
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_lock(&data->philo[i].mut_num_meals);
			if (data->philo[i].meals >= data->nb_meals)
				full_philos++;
            else
				i = -1; // ✅ Forces rechecking all philosophers if one hasn’t eaten enough
			pthread_mutex_unlock(&data->philo[i].mut_num_meals);
			i++;
		}
		if (full_philos == data->num_philos) // ✅ All philosophers have eaten enough
		{
            end_simulation(data); // ✅ Stops simulation & marks all as dead
			return (NULL);
		}
		usleep(1000); // ✅ Sleep to prevent excessive CPU usage
	}
	return (NULL);
}
*/