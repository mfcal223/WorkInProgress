/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+  	+#+           */
/*   Created: 2025/03/17 12:01:40 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 14:20:32 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Checks whether the simulation should stop.
 */
int	should_stop_monitoring(t_data *data)
{
	pthread_mutex_lock(&data->death_lock);
	if (!data->keep_iterating || data->dead)
	{
		pthread_mutex_unlock(&data->death_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->death_lock);
	return (0);
}

/**
 * Iterates through all philosophers and checks if any have died.
 */
int	monitor_philosopher_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (has_died(&data->philo[i]))
		{
			end_simulation(data);
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * Monitors if a philosopher has died.
 * explicitly call end_simulation() when death is detected
 * return NULL when the monitoring stops.
 */
void	*check_death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (!data)
		return (NULL);
	while (1)
	{
		if (should_stop_monitoring(data))
			break ;
		if (monitor_philosopher_death(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
