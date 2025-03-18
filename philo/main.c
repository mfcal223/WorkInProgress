/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:09 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 09:39:11 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*Handles argument parsing, initialization, and starting the simulation. */

int	sync_threads(t_data *data)
{
	int	i;

	end_simulation(data);// First mark simulation as ending
	// Give threads a moment to notice the flag
	usleep(1000);
	// ✅ Wait for the death monitor to finish
	if (pthread_join(data->death_monitor, NULL) != 0)
	{
		printf("Error: Failed to join death monitor thread\n");
		return (ERR);
	}	
	// ✅ If `nb_meals` is set, wait for `check_meals()` to finish
	if (data->nb_meals > 0)
	{
		if (pthread_join(data->meal_monitor, NULL) != 0)
		{
			printf("Error: Failed to join meal  monitor thread\n");
			return (ERR);
		}	
	}
	// ✅ Wait for all philosopher threads
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL) != 0)
		{
			printf("Error: Failed to join philosophers thread\n");
			return (ERR);
		}
		i++;
	}
	return (0);
}

int	init_admin(int ac, char **av)
{
	t_data	data;
	
	if (init_data(&data, ac, av) != 0)
		return (ERR);
	if (init_philosophers(&data))
		return (ERR);
	if (init_threads(&data))
		return (ERR);
	if (sync_threads(&data))
		return (ERR);
	close_adm(&data, "Exiting simulation.\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!validate_input(ac, av))
		return (1);
	printf("All inputs are valid!\n");
	if (init_admin(ac, av) != 0)
	{
		close_adm(&data, "Program failed.\n");
		return (ERR);
	}
	return (0);
}
