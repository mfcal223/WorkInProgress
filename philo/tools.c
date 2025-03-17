/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:40:22 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 09:40:22 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include "philo.h"

/**
 * A precise delay function that ensures the thread wakes up at the right time.
 */
void	wait_until(uint64_t wait_time)
{
	uint64_t	start_time;

	start_time = get_time_ms(); // Get the current time
	while ((get_time_ms() - start_time) < wait_time)
		usleep(500); // Sleep in small increments (500 μs) for better accuracy
}


/*
Use a mutex (print_lock) to prevent multiple threads from printing simultaneously.
Take three parameters:
timestamp_in_ms: Current timestamp in milliseconds
philo_id: Philosopher's ID
msg: Message (one of the macros like EAT, THINK, etc.)
*/
void	print_msg(t_philo *philo, const char *msg)
{
	uint64_t	timestamp;

	pthread_mutex_lock(&philo->data->print_lock);
	timestamp = get_time_ms() - philo->data->start_time;
	if (philo->data->keep_iterating)  // ✅ Print only if simulation is running
		printf("%lu %d %s\n", timestamp, philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}

/* Convert string to integer safely (without libft) */
long	ft_atol(const char *str)
{
	int		i;
	long	res;
	//int		sign;

	i = 0;
	res = 0;
	//sign = 1;
	/*if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}*/
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1); // Overflow protection
		i++;
	}
	return (res);
}

uint64_t	get_time_ms(void)
{
	struct timeval	tv;
	uint64_t	ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}

