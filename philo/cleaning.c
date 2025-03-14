/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:40:04 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 09:40:04 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* if fork allocation fails mid-way */
void	free_partial_forks(t_data *data, int failed_index)
{
	int	i;

	i = 0;
	while (i < failed_index)
	{
		free(data->philo[i].left_fork); // Free only the successfully allocated forks
		i++;
	}
	close_adm(data, "Error: Fork memory allocation failed\n"); // ✅ Now 'data' is available!
}
/* Destroy all mutexes before freeing */
void	destroy_mutexes(t_data *data)
{
	int	i;

	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->death_lock);
	i = 0;
	while (i < data->num_philos)
	{
		// ✅ Ensure mutex is unlocked before destroying
		pthread_mutex_lock(&data->death_lock);
		if (data->simulation_running)
		{
            if (pthread_mutex_trylock(&data->philo[i].eating_lock) == 0)
				pthread_mutex_unlock(&data->philo[i].eating_lock);
			if (pthread_mutex_trylock(data->philo[i].left_fork) == 0)
				pthread_mutex_unlock(data->philo[i].left_fork);
		}
		pthread_mutex_unlock(&data->death_lock);
		pthread_mutex_destroy(&data->philo[i].eating_lock);
		pthread_mutex_destroy(data->philo[i].left_fork);
		free(data->philo[i].left_fork);  // Free each left fork
		i++;
	}
}

/* Free philosophers array */
void	free_philosophers(t_data *data)
{
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->threads)
	{
		free(data->threads);
		data->threads = NULL;
	}
}

/* Master function to free all allocated memory */
void	free_data(t_data *data)
{
	destroy_mutexes(data);
	free_philosophers(data);
}

void	close_adm(t_data *data, char *str)
{
	printf("%s", str);
	free_data(data);
}