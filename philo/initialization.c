/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:25 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/17 15:42:20 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * The function that initializes and starts all threads.
 * Step 1: Create philosopher threads. 1 thread per number of philosophers
 * Step 2: Create monitoring thread for checking deaths. 
 * Step 3: Create monitoring thread for meal count (if `num_meal` is set)
 */
int	init_threads(t_data *data)
{
	int	i;

	data->start_time = get_time_ms();
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				philo_routine, &data->philo[i]) != 0)
			return (close_adm(data, "Err: Failed creation philo_ths\n"), 1);
		i++;
	}
	if (pthread_create(&data->death_monitor, NULL, check_death, data) != 0)
		return (close_adm(data, "Err: Failed creation death_monitor\n"), 1);
	if (data->num_meal > 0)
	{
		if (pthread_create(&data->meal_monitor, NULL, check_meals, data) != 0)
			return (close_adm(data, "Err: Failed creation meal_monitor\n"), 1);
	}
	return (0);
}

/**
 * Initialize main mutexes
 * Initialize fork mutexes = as many as number of philosophers
 */
int	init_data_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->print_lock, NULL) != 0
		|| pthread_mutex_init(&data->death_lock, NULL) != 0
		|| pthread_mutex_init(&data->mut_die_t, NULL) != 0)
		return (close_adm(data, "Error: Mutex initialization failed\n"), 1);
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (close_adm(data, "Error: Fork mutex init failed\n"), 1);
		i++;
	}
	return (0);
}

/**
 * Initialize the main data structure.
 * allocates memory for threads, struc philo, and fork mutex
 * allocates philo_ths: 1 thread per number of philosophers
 * allocates forks: 1 fork per number of philosophers
 */
int	init_data(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->num_meal = ft_atol(av[5]);
	else
		data->num_meal = -1;
	data->keep_iterating = 1;
	data->dead = 0;
	data->finished = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	data->philo_ths = malloc(sizeof(pthread_t) * data->num_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->philo || !data->philo_ths || !data->forks)
		return (close_adm(data, "Error: Memory allocation failed\n"), 1);
	if (init_data_mutexes(data) != 0)
		return (1);
	return (0);
}

/**
 * keeps forks as an array, where each philosopher only depends on their index
 * and previous.
 */
int	init_forks(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("Error: Mutex initialization failed\n");
			return (1);
		}
		i++;
	}
	philo[0].left_fork = &data->forks[0];
	philo[0].right_fork = &data->forks[data->num_philos - 1];
	i = 1;
	while (i < data->num_philos)
	{
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[i - 1];
		i++;
	}
	return (0);
}

/**
 * Initialize philosophers structure
 * Initialize individual mutexes

 */
int	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].status = idle;
		data->philo[i].meals = 0;
		data->philo[i].last_eat = get_time_ms();
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].data = data;
		if (pthread_mutex_init(&data->philo[i].mut_last_eat, NULL) != 0
			|| pthread_mutex_init(&data->philo[i].mut_num_meals, NULL) != 0)
			return (close_adm(data, "Err: Philos Mutex init failed \n"), 1);
		i++;
	}
	init_forks(data);
	return (0);
}
