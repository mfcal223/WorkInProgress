/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:09 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 14:01:09 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*Handles argument parsing, initialization, and starting the simulation. */

/*
starts philosopher threads and the monitor thread (to track deaths).
gets start time: ensures accurate timestamps for all printed events.
Ensures main thread waits for all philosophers and the monitor thread.
Prevents zombie threads or crashes.
*/

int	create_threads(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->num_philos) // ✅ Create philosopher threads
	{
		if (pthread_create(&data->threads[i], NULL, philosopher_routine, &data->philo[i]) != 0)
		{
			close_adm(data, "Error: Failed to create philosopher thread\n");
			return (ERR);
		}
		//printf("Creating philosopher thread %d\n", i + 1);//debug
		i++;
	}
	if (pthread_create(monitor, NULL, check_death, data) != 0) // ✅ Create monitor thread
	{
		close_adm(data, "Error: Failed to create monitor thread\n");
		return (ERR);
	}
	return (0);
}

void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	data->start_time = get_time_ms(); // ✅ Mark simulation start time
	if (create_threads(data, &monitor) != 0) // ✅ Create threads
		return ;
	i = 0;
	while (i < data->num_philos) // ✅ Wait for all philosopher threads to finish
	{
		pthread_mutex_lock(&data->death_lock);
		if (!data->simulation_running)
		{
			pthread_mutex_unlock(&data->death_lock);
			break;  // ✅ Stop waiting if simulation has ended
		}
		pthread_mutex_unlock(&data->death_lock);
		pthread_join(data->threads[i], NULL);
		i++;
	}
	pthread_join(monitor, NULL); // ✅ Wait for monitor thread to finish
}


int	main(int ac, char **av)
{
	t_data	data;

	if (!validate_input(ac, av))
		return (1);
	printf("All inputs are valid!\n");
	if (init_data(&data, av) || init_philosophers(&data))
	{
		close_adm(&data, "Initialization failed!\n");
		return (1);
	}
	start_simulation(&data);
	close_adm(&data, "Exiting simulation.\n");
	return (0);
}
/*void	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	data->start_time = get_time_ms(); // Mark simulation start time
	i = 0;
	while (i < data->num_philos)// ✅ Create philosopher threads
	{
		if (pthread_create(&data->threads[i], NULL, philosopher_routine, &data->philo[i]) != 0)
		{
			close_adm(data, "Error: Failed to create philosopher thread\n");
			return;
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, check_death, data) != 0) // ✅ Create monitor thread to check for deaths
	{
		close_adm(data, "Error: Failed to create monitor thread\n");
		return;
	}
	i = 0;
	while (i < data->num_philos) // ✅ Wait for all philosopher threads to finish
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	pthread_join(monitor, NULL);	// ✅ Wait for monitor thread to finish
}*/