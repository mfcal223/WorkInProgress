/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:29:25 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/20 10:29:25 by mcalciat         ###   ########.fr       */
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

void	end_simulation(t_data *data)
{
	int	dying_philo;

	pthread_mutex_lock(&data->death_lock);
	if (!data->keep_iterating)
	{
		pthread_mutex_unlock(&data->death_lock);
		return ;
	}
	data->keep_iterating = 0;
	data->dead = 1;
	pthread_mutex_unlock(&data->death_lock);
	dying_philo = find_dying_philo(data);
	if (dying_philo >= 0)
	{
		print_msg(&data->philo[dying_philo], DIED);
	}
}

/**
 * Checks if a philosopher has exceeded their time to die.
 * step 1 check if simulation is already stopping
 * Step 2 Check time since last meal and status
 * step 3 Check death condition: if philosopher exceeded time_to_die, then dead
 * SETS THE DEAD FLAG = 1
 * return 1 if the philosopher has died, 0 otherwise.
 */
int	has_died(t_philo *philo)
{
	uint64_t	current_time;
	uint64_t	time_since_last_meal;
	int			is_dead;
	t_status	current_status;

	pthread_mutex_lock(&philo->data->death_lock);
	is_dead = philo->data->dead;
	current_status = philo->status;
	pthread_mutex_unlock(&philo->data->death_lock);
	if (is_dead)
		return (1);
	current_time = get_time_ms();
	pthread_mutex_lock(&philo->mut_last_eat);
	time_since_last_meal = current_time - philo->last_eat;
	pthread_mutex_unlock(&philo->mut_last_eat);
	if (time_since_last_meal > philo->time_to_die && current_status != eat)
	{
		return (1);
	}
	return (0);
}

/**
 * gets the time to die of the philosopher.
 */
uint64_t	get_die_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_die_t);
	time = data->time_to_die;
	pthread_mutex_unlock(&data->mut_die_t);
	return (time);
}

int	check_keep_iterating(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_lock);
	result = (data->keep_iterating && !data->dead);
	pthread_mutex_unlock(&data->death_lock);
	return (result);
}
