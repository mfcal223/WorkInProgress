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

void	free_philo_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philo[i].mut_num_meals);
		pthread_mutex_destroy(&data->philo[i].mut_last_eat);
		i++;
	}
}

void	free_global_mutexes(t_data *data)
{
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->death_lock);
}

void	free_threads(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_join(data->death_monitor, NULL) != 0)
		printf("Warning: Failed to join death monitor thread.\n");
	if (data->nb_meals > 0 && pthread_join(data->meal_monitor, NULL) != 0)
		printf("Warning: Failed to join meal monitor thread.\n");
	while (i < data->num_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL) != 0)
			printf("Warning: Failed to join philosopher thread %d.\n", i);
		i++;
	}
}

/* Master function to free all allocated memory */
void	free_data(t_data *data)
{
	free_threads(data);
	free_philo_mutexes(data);
	free_global_mutexes(data);
	free(data->philo_ths);
	free(data->philo);
	free(data->forks);
}

void	close_adm(t_data *data, char *str)
{
	if (str)
		printf("%s", str);
	free_data(data);
}