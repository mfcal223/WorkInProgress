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

void	update_status(t_data *data, t_philo *philo, t_status new_status,
			int already_locked)
{
	if (!already_locked)
		pthread_mutex_lock(&data->death_lock);
	if (data->dead == 0)
		philo->status = new_status;
	if (!already_locked)
		pthread_mutex_unlock(&data->death_lock);
}

/** Releases both forks after eating or failing to acquire both. */
void	drop_forks(t_philo *philo)
{
	int	left_index;
	int	right_index;

	left_index = philo->left_fork - philo->data->forks;
	right_index = philo->right_fork - philo->data->forks;
	if (left_index < right_index)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

void	sleep_philo(t_philo *philo)
{
	update_status(philo->data, philo, asleep, 0);
	print_msg(philo, SLEEP);
	wait_until(philo->data->time_to_sleep);
}

void	think_philo(t_philo *philo)
{
	update_status(philo->data, philo, think, 0);
	print_msg(philo, THINK);
	wait_until(5);
}
