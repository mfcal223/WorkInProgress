/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:55:19 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 10:09:17 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_philo(t_philo *philo)
{
	// Update status safely
	update_status(philo->data, philo, asleep, 0);

	// Print sleeping message
	print_msg(philo, SLEEP);

	// Wait for sleeping time
	wait_until(philo->data->time_to_sleep);
}

void	think_philo(t_philo *philo)
{
	// Update status safely
	update_status(philo->data, philo, think, 0);

	// Print thinking message
	print_msg(philo, THINK);

	// Philosophers wait a short time before trying to eat again
	wait_until(5);
}
