/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:51:59 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/17 15:13:11 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * Checks if a philosopher has exceeded their time to die.
 * @return 1 if the philosopher has died, 0 otherwise.
 */
int	has_died(t_philo *philo)
{
	uint64_t	current_time;
	uint64_t	time_since_last_meal;

	current_time = get_time_ms();

	// Lock last meal time for thread safety
	pthread_mutex_lock(&philo->mut_last_eat);
	time_since_last_meal = current_time - philo->last_eat;
	pthread_mutex_unlock(&philo->mut_last_eat);

	// If the philosopher exceeded time_to_die and is not eating, they die
	if (time_since_last_meal > philo->time_to_die && philo->status != eat)
	{
		pthread_mutex_lock(&philo->data->death_lock);
		if (philo->data->keep_iterating) 
		{
			philo->data->dead = 1;
			print_msg(philo, DIED);
		}
		pthread_mutex_unlock(&philo->data->death_lock);
		return (1);
	}
	return (0);
}

uint64_t	check_die_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_die_t);
	time = data->time_to_die;
	pthread_mutex_unlock(&data->mut_die_t);
	return (time);
}

/*	The function ft_get_die() gets the time to die of the philosopher. 
	It receives a data structure as an argument. It locks the mutex of the dying
	time, gets the dying time, and unlocks the mutex of the dying time. Finally,
	it returns the dying time. */

uint64_t	check_eat_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_eat_t);
	time = data->time_to_eat;
	pthread_mutex_unlock(&data->mut_eat_t);
	return (time);
}

/*	The function ft_get_eat() gets the time to eat of the philosopher. 
	It receives a data structure as an argument. It locks the mutex of the 
	eating time, gets the eating time, and unlocks the mutex of the eating 
	time. Finally, it returns the eating time. */

uint64_t	ft_get_last_eat(t_philo *philo)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->mut_last_eat);
	time = philo->last_eat;
	pthread_mutex_unlock(&philo->mut_last_eat);
	return (time);
}

/*	The function ft_get_last_eat() gets the last meal time of the philosopher.
It receives a philosopher as an argument. It locks the mutex of the last 
meal, gets the last meal time, and unlocks the mutex of the last meal. 
Finally, it returns the last meal time. */
	
int	check_keep_iterating(t_data *data)
{
	int keep;

	pthread_mutex_lock(&data->death_lock);
	keep = data->keep_iterating;
	pthread_mutex_unlock(&data->death_lock);
	return (keep);
}
