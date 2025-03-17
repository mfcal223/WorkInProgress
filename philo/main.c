/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:09 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/17 15:49:33 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*Handles argument parsing, initialization, and starting the simulation. */

int	sync_threads(t_data *data)
{
	int	i;
    // ✅ Ensure `keep_iterating` is set to 0 before joining threads
	pthread_mutex_lock(&data->death_lock);//could this be replace with end_simulation()?
	data->keep_iterating = 0;
	pthread_mutex_unlock(&data->death_lock);

	// ✅ Wait for the death monitor to finish
	if (pthread_join(data->death_monitor, NULL) != 0)
		return (close_adm(data, "Error: Failed to join death monitor thread\n"), 1);

	// ✅ If `nb_meals` is set, wait for `check_meals()` to finish
	if (data->nb_meals > 0)
	{
		if (pthread_join(data->meal_monitor, NULL) != 0)
			return (close_adm(data, "Error: Failed to join meal monitor thread\n"), 1);
	}

	// ✅ Wait for all philosopher threads
	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL) != 0)
			return (close_adm(data, "Error: Failed to join philosopher thread\n"), 1);
		i++;
	}
	return (0);
}


int	init_admin(int ac, char **av)
{
	t_data	data;
	
	if (init_data(&data, ac, av) != 0)
		return (ERR);
	init_philosophers(&data);
	init_threads(&data);
	sync_threads(&data);
	close_adm(&data, "Exiting simulation.\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!validate_input(ac, av))
		return (1);
	printf("All inputs are valid!\n");
	if (init_admin(ac, av) != 0)//calling the managing function
	{
		close_adm(&data, "Program failed.\n");
		return (ERR);
	}
	
	return (0);
}
