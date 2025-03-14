/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:25 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 11:47:07 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Initialize the main data structure.
 Allocate memory for philosophers and threads
Initilize global mutexes */
int	init_data(t_data *data, char **av)
{
	data->num_philos = ft_atol(av[1]);
	data->start_time = 0;
	data->simulation_running = 1;
	data->dead = 0;
	data->finished = 0;
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	if (av[5])
	        data->meals_required = ft_atol(av[5]);
        else
	        data->meals_required = -1;      
	
	data->philo = malloc(sizeof(t_philo) * data->num_philos);
	data->threads = malloc(sizeof(pthread_t) * data->num_philos);
	if (!data->philo || !data->threads)
        {
			close_adm(data, "Error: Data memory allocation failed\n");
            return (ERR);
        }
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->death_lock, NULL);
	return (0);
}

/* Initialize philosophers and assign fork mutexes
Circular assignment for right forks */
int	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philo[i].id = i + 1;
		data->philo[i].status = idle;
		data->philo[i].eat_count = 0;
		data->philo[i].last_meal_time = 0;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].data = data;
		pthread_mutex_init(&data->philo[i].eating_lock, NULL);
		data->philo[i].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!data->philo[i].left_fork)
		{
			free_partial_forks(data, i);
			return (ERR);
		}		
		pthread_mutex_init(data->philo[i].left_fork, NULL);
		i++;
	}
		// ✅ Now assign right forks after all left forks are initialized
		i = 0;
		while (i < data->num_philos)
		{
			if (i == data->num_philos - 1)
				data->philo[i].right_fork = data->philo[0].left_fork;
			else
				data->philo[i].right_fork = data->philo[i + 1].left_fork;
			i++;
		}
	return (0);
}
