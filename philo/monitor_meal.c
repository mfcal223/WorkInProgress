/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_meal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+  	+#+           */
/*   Created: 2025/03/17 12:01:40 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 14:20:32 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Checks if the simulation should stop.
 */
int	should_stop_meal_monitoring(t_data *data)
{
	int	should_end;

	should_end = 0;
	pthread_mutex_lock(&data->death_lock);
	if (!data->keep_iterating || data->dead)
		should_end = 1;
	pthread_mutex_unlock(&data->death_lock);
	return (should_end);
}

/**
 * Iterates through philosophers and counts how many have eaten enough.
 */
int	count_full_philosophers(t_data *data)
{
	int	i;
	int	full_philos;
	int	reset_check;

	full_philos = 0;
	reset_check = 0;
	i = 0;
	while (i < data->num_philos && !reset_check)
	{
		pthread_mutex_lock(&data->philo[i].mut_num_meals);
		if (data->philo[i].meals >= data->num_meal)
			full_philos++;
		else
			reset_check = 1;
		pthread_mutex_unlock(&data->philo[i].mut_num_meals);
		i++;
	}
	if (!reset_check && full_philos == data->num_philos)
		return (1);
	return (0);
}

/**
 * Monitors if all philosophers have eaten enough times.
 * if 1 philo has not eat enough, then flag = true
 * Calls end_simulation() when all philosophers have eaten enough
 * return NULL when the monitoring stops.
 */
void	*check_meals(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (should_stop_meal_monitoring(data))
			break ;
		if (count_full_philosophers(data))
		{
			end_simulation(data);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
/*
void	*check_meals(void *arg)
{
	t_data *data;
	int i;
	int full_philos;
	int should_end;
	int reset_check;

	data = (t_data *)arg;
	while (1)
	{
		should_end = 0;
		pthread_mutex_lock(&data->death_lock);
		if (!data->keep_iterating || data->dead)
			should_end = 1;
		pthread_mutex_unlock(&data->death_lock);
		if (should_end)
			break ;
		full_philos = 0;
		i = 0;
		reset_check = 0;
		while (i < data->num_philos && !reset_check)
		{
			pthread_mutex_lock(&data->philo[i].mut_num_meals);
			if (data->philo[i].meals >= data->num_meal)
				full_philos++;
			else
				reset_check = 1;
			pthread_mutex_unlock(&data->philo[i].mut_num_meals);
			i++;
		}
		if (!reset_check && full_philos == data->num_philos)
		{
			end_simulation(data);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
    */