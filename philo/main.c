/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:23:09 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 15:13:55 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*Handles argument parsing, initialization, and starting the simulation. */


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
