/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:39:56 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/18 14:15:35 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 *  Check if the philosopher is already dead
 * Update last meal time safely
 * Print eating message
 * Increase meal count safely
 * Wait for eating time
 * Release both forks 
*/
int	eat_philo(t_philo *philo)
{
	if (has_died(philo))
	{
		drop_forks(philo);
		return (1);
	}
	update_status(philo->data, philo, eat, 0);
	pthread_mutex_lock(&philo->mut_last_eat);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&philo->mut_last_eat);
	print_msg(philo, EAT);
	pthread_mutex_lock(&philo->mut_num_meals);
	philo->meals++;
	pthread_mutex_unlock(&philo->mut_num_meals);
	wait_until(philo->data->time_to_eat);
	drop_forks(philo);
	return (0);
}

/**
 * Always lock the lower-numbered fork first
 */
int	lock_forks(t_philo *philo, int left_index, int right_index)
{
	if (left_index < right_index)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			return (1);
		print_msg(philo, TAKE_FORKS);
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			return (1);
		print_msg(philo, TAKE_FORKS);
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
	}
	return (0);
}

int	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, TAKE_FORKS);
	wait_until(philo->data->time_to_die);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

/**
 * Tries to take the right and left forks.
 * return 0 if forks were successfully taken, 1 if simulation should stop.
 * Check if the philosopher is already dead before taking forks
 * Handle case of single philosopher
 * Calculate the actual indices of the forks.
 */
int	take_forks(t_philo *philo)
{
	int	left_index;
	int	right_index;

	if (has_died(philo))
		return (1);
	if (philo->data->num_philos == 1)
		return (handle_single_philo(philo));
	left_index = philo->left_fork - philo->data->forks;
	right_index = philo->right_fork - philo->data->forks;
	if (lock_forks(philo, left_index, right_index) != 0)
		return (1);
	print_msg(philo, TAKE_FORKS);
	return (0);
}

/**
 * Routine that each philosopher follows.
 * return NULL when the thread ends.
 * If philosopher ID is even, delay to avoid deadlocks
 * Step 1: Check if simulation should stop before any action
 * Step 2: Check if philosopher already died before trying to eat
 * Step 3: Try to eat
 * Step 4: Check if anyone died again before sleeping
 * Step 5: Sleep
 * Step 6: Think
 */
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		wait_until(10);
	while (1)
	{
		if (!check_keep_iterating(philo->data))
			break ;
		if (has_died(philo))
			break ;
		if (take_forks(philo) != 0)
			break ;
		if (eat_philo(philo) != 0)
			break ;
		if (!check_keep_iterating(philo->data))
			break ;
		sleep_philo(philo);
		think_philo(philo);
	}
	return (NULL);
}
