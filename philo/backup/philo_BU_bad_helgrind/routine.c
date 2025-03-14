/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:39:56 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 13:58:01 by mcalciat         ###   ########.fr       */
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

/*Prints thinking status.
✅ No delay needed (thinking time is implicit before taking forks again).
 */
void	think_philo(t_philo *philo)
{
	print_msg(philo, THINK);

}

/*✅ Prints sleeping status.
✅ Uses usleep() to simulate sleep time.
*/
void	sleep_philo(t_philo *philo)
{
	print_msg(philo, SLEEP);
	usleep(philo->data->time_to_sleep * 1000);
}

/*  Releases both fork mutexes so other philosophers can eat.
forks are never left locked due to a philosopher dying mid-simulation. */
void release_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->death_lock);
    if (philo->data->simulation_running)//only if simulation is running
    {
        if (philo->left_fork)
            pthread_mutex_unlock(philo->left_fork);
        if (philo->right_fork)
            pthread_mutex_unlock(philo->right_fork);
    }
    pthread_mutex_unlock(&philo->data->death_lock);
}

/*
✅ Locks eating_lock to update last_meal_time safely.
✅ Increments eat_count to track meals.
*/
void	eat_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating_lock);
	philo->last_meal_time = get_time_ms();
	pthread_mutex_unlock(&philo->eating_lock);
	print_msg(philo, EAT);
	usleep(philo->data->time_to_eat * 1000);
	philo->eat_count++;
}

/*
Use an ordering mechanism toa void deadlocks:

*/
void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);  // ✅ Always take left fork first
	print_msg(philo, TAKE_FORKS);

	pthread_mutex_lock(philo->right_fork);
	print_msg(philo, TAKE_FORKS);
}

/*
Staggered start for even philosophers to prevent deadlocks.
Short usleep(500) delay after thinking to spread out execution.
*/
void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0) // Stagger start times to prevent deadlocks
		usleep(philo->data->time_to_eat * 500);  // ✅ Half the eating time delay before starting
	if (philo->data->num_philos == 1)
	{
		print_msg(philo, THINK);  // ✅ Use print_msg() for thread-safe logging
		usleep(philo->data->time_to_die * 1000);  // Wait until death
		return NULL;
	}
	while (1)
	{
		pthread_mutex_lock(&philo->data->death_lock);
		if (!philo->data->simulation_running)  // ✅ Check simulation_running with a lock
		{
			pthread_mutex_unlock(&philo->data->death_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->data->death_lock);

		take_forks(philo);
		eat_philo(philo);
		release_forks(philo);
		sleep_philo(philo);
		think_philo(philo);
		usleep(500); // Short thinking delay to prevent instant fork grabbing
	}
	return (NULL);
}

/*
The monitor thread constantly checks if any philosopher has died:
Iterates through all philosophers.
Compares current_time - last_meal_time to time_to_die: how long it has been since the philosopher last ate.
Uses pthread_mutex_lock() to safely check last_meal_time.
If a philosopher is dead, prints a death message and stops the simulation.
Runs in a loop until the simulation ends.
*/
void	*check_death(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (data->simulation_running)
	{
		i = 0;
		pthread_mutex_lock(&data->print_lock);//DEBUG
		printf("Monitor thread started!\n");  // DEBUG 
		pthread_mutex_unlock(&data->print_lock);//DEBUG
		while (i < data->num_philos)
		{
			pthread_mutex_lock(&data->philo[i].eating_lock);
			if (get_time_ms() - data->philo[i].last_meal_time > data->time_to_die)
			{
				pthread_mutex_unlock(&data->philo[i].eating_lock);
				pthread_mutex_lock(&data->death_lock);
				data->simulation_running = 0;
				pthread_mutex_unlock(&data->death_lock);
				
				print_msg(&data->philo[i], DIED);
				// ✅ Ensure all forks are released before stopping
				pthread_mutex_unlock(data->philo[i].left_fork);
				pthread_mutex_unlock(data->philo[i].right_fork);
				return (NULL); // ✅ Exit immediately on death
			}
			// ✅ Check if all philosophers are finished
			if (data->meals_required > 0 && data->philo[i].eat_count >= data->meals_required)
				data->finished++;

			if (data->finished >= data->num_philos)
			{
				pthread_mutex_lock(&data->death_lock);
				data->simulation_running = 0;  // ✅ Now safely modifying the flag
				pthread_mutex_unlock(&data->death_lock);
			}
			pthread_mutex_unlock(&data->philo[i].eating_lock);
			i++;
		}
		usleep(1000); // Small delay to avoid high CPU usage
	}
	return (NULL);
}

