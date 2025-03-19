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
/* ROUTINE = 
Each philosopher follows a loop:
1. Takes forks (locking the fork mutexes).
2. Eats (updates last_meal_time and sleeps for time_to_eat ms).
3. Releases forks (unlocking the fork mutexes).
4. Sleeps (usleep(time_to_sleep * 1000)).
5 .Thinks before trying to eat again.
*/
/** Releases both forks after eating or failing to acquire both. */
void	drop_forks(t_philo *philo)
{
	int left_index;
    int right_index;
    // Calculate indices
    left_index = philo->left_fork - philo->data->forks;
    right_index = philo->right_fork - philo->data->forks;
    
    // Release in reverse order of acquisition
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

int	eat_philo(t_philo *philo)
{
    // Check if the philosopher is already dead
	if (has_died(philo))
	{
		drop_forks(philo);
		return (1);
	}
	update_status(philo->data, philo, eat, 0);
	// Update last meal time safely
	pthread_mutex_lock(&philo->mut_last_eat);
	philo->last_eat = get_time_ms();
	pthread_mutex_unlock(&philo->mut_last_eat);
	// Print eating message
	print_msg(philo, EAT);
	// Increase meal count safely
	pthread_mutex_lock(&philo->mut_num_meals);
	philo->meals++;
	pthread_mutex_unlock(&philo->mut_num_meals);
	// Wait for eating time
	wait_until(philo->data->time_to_eat);
	// Release both forks
	drop_forks(philo);
	return (0);
}

/**
 * Tries to take the right and left forks.
 * @return 0 if forks were successfully taken, 1 if simulation should stop.
 */
int	take_forks(t_philo *philo)
{
	int	left_index;
    int	right_index;
    // Check if the philosopher is already dead before taking forks
	if (has_died(philo))
        return (1);
	// Handle case of single philosopher
    if (philo->data->num_philos == 1)
    {
        pthread_mutex_lock(philo->right_fork);
        print_msg(philo, TAKE_FORKS);
        wait_until(philo->data->time_to_die);
        pthread_mutex_unlock(philo->right_fork);
        return (1);
    }
	// Calculate the actual indices of the forks
    left_index = philo->left_fork - philo->data->forks;
    right_index = philo->right_fork - philo->data->forks;
    // Always lock the lower-numbered fork first
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
	print_msg(philo, TAKE_FORKS);
	return (0);
}

/**
 * Routine that each philosopher follows.
 * return NULL when the thread ends.
 */
void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
    //printf("DEBUG: Philosopher %d starting routine\n", philo->id); // DEBUG
	// If philosopher ID is even, delay to avoid deadlocks
	if (philo->id % 2 == 0)
        wait_until(10);
	while (1)
	{
		// ✅ Step 1: Check if simulation should stop before any action
		if (!check_keep_iterating(philo->data))
        {
            //printf("DEBUG 1-pr: Philo %d breaking because keep_iterating is false\n", 
                   //philo->id); // DEBUG
            break;
        }
		// ✅ Step 2: Check if philosopher already died before trying to eat
		if (has_died(philo))
			break;
		// ✅ Step 3: Try to eat
		if (take_forks(philo) != 0) 
			break;
		if (eat_philo(philo) != 0) 
			break;
		// ✅ Step 4: Check again before sleeping
		if (!check_keep_iterating(philo->data))
        {
            //printf("DEBUG 2-pr: Philo %d breaking because keep_iterating is false\n", 
                   //philo->id); // DEBUG
            break;
        }
		// ✅ Step 5: Sleep
		sleep_philo(philo);
		// ✅ Step 6: Think
		think_philo(philo);
	}
	//printf("DEBUG: Philosopher %d ending routine\n", philo->id);
	return (NULL);
}
/*
int	take_forks(t_philo *philo)
{
    // Check if the philosopher is already dead before taking forks
	if (has_died(philo))
        return (1);
	// Lock the right fork first
	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, TAKE_FORKS);
	// If the philosopher has only one fork, they can't eat
	if (philo->data->num_philos == 1)//handling 1 philosopher
	{
		wait_until(philo->data->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		//drop_forks(philo); //fix "Unlocking Not-Locked Mutex" 
		return (1);
	}
	// Try to lock the left fork
	if (pthread_mutex_lock(philo->left_fork) != 0)
	{
		//drop_forks(philo);//fix "Unlocking Not-Locked Mutex"
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_msg(philo, TAKE_FORKS);
	return (0);
}
*/ 

