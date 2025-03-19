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

/*
 * The function that initializes and starts all threads.
 * @return 0 on success, 1 on failure.
 */
int	init_threads(t_data *data)
{
	int	i;

	data->start_time = get_time_ms();
	// Step 1: Create philosopher threads
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL, 
			philo_routine, &data->philo[i]) != 0)
			return (close_adm(data, "Error: Failed to create philosopher thread\n"), 1);
		i++;
	}
	// Step 2: Create monitoring thread for checking deaths
	if (pthread_create(&data->death_monitor, NULL, check_death, data) != 0)
		return (close_adm(data, "Error: Failed to create death monitor thread\n"), 1);
	// Step 3: Create monitoring thread for meal count (if `nb_meals` is set)
	if (data->nb_meals > 0)
	{
		if (pthread_create(&data->meal_monitor, NULL, check_meals, data) != 0)
			return (close_adm(data, "Error: Failed to create meal monitor thread\n"), 1);
	}
	return (0);
}

int	init_data_mutexes(t_data *data)
{
	int	i;

	// Initialize main mutexes
	if (pthread_mutex_init(&data->print_lock, NULL) != 0
		|| pthread_mutex_init(&data->death_lock, NULL) != 0
		|| pthread_mutex_init(&data->mut_eat_t, NULL) != 0
		|| pthread_mutex_init(&data->mut_die_t, NULL) != 0
		|| pthread_mutex_init(&data->mut_sleep_t, NULL) != 0)
		return (close_adm(data, "Error: Mutex initialization failed\n"), 1);
	// Initialize fork mutexes
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (close_adm(data, "Error: Fork mutex initialization failed\n"), 1);
		i++;
	}
	return (0);
}

/* Initialize the main data structure.
 */
int	init_data(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac == 6) // If the optional 6th argument is provided
		data->nb_meals = ft_atol(av[5]);
	else
		data->nb_meals = -1; // No meal limit
	data->keep_iterating = 1;
	data->dead = 0;
	data->nb_full_p = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	data->philo_ths = malloc(sizeof(pthread_t) * data->num_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->philo || !data->philo_ths || !data->forks)
		return (close_adm(data, "Error: Memory allocation failed\n"), 1);
	if (init_data_mutexes(data) != 0) //  Initialize Mutexes
		return (1);
	return (0);
}

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
/* keeps forks as an array, where each philosopher only 
depends on their index and previous.*/

/* Initialize philosophers and assign fork mutexes
Forks assign as an array */
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
		// Initialize individual mutexes
		if (pthread_mutex_init(&data->philo[i].mut_last_eat, NULL) != 0
			|| pthread_mutex_init(&data->philo[i].mut_num_meals, NULL) != 0
			/*|| pthread_mutex_init(&data->philo[i].mut_state, NULL) != 0*/)
			return (close_adm(data, "Err: Philos Mutex init failed \n"), 1);
		i++;
	}
	init_forks(data);
	return (0);
}

