/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:09 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 13:55:21 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * uses pthread_join to ensure threads are in sync
 * ✅ Wait for the death monitor to finish
 * ✅ If `num_meal` is set, wait for `check_meals()` to finish
 * ✅ Wait for all philosopher threads
 */
int	sync_threads(t_data *data)
{
	int	i;

	if (pthread_join(data->death_monitor, NULL) != 0)
	{
		return (ERR);
	}
	if (data->num_meal > 0)
	{
		if (pthread_join(data->meal_monitor, NULL) != 0)
		{
			return (ERR);
		}
	}
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL) != 0)
		{
			return (ERR);
		}
		i++;
	}
	return (0);
}

/**
 * initializes structures, mutexes and threads.
 * coordinates that with sync_threads
 * executes the closing functions if all works ok 
 */
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
	{
		printf("Error: Failed to join threads\n");
		return (ERR);
	}
	close_adm(&data, "Exiting simulation.\n");
	return (0);
}

/** 
 * Handles argument parsing and initialization
 * executes closing functions if there is an error
*/
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
