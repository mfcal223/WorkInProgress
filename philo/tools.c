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

static int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
msg: Message (one of the macros like EAT, THINK, etc.)
Attention: check_keep_iterating() uses death_lock mutex
*/
void	print_msg(t_philo *philo, const char *msg)
{
	uint64_t	timestamp;
	int			should_print;

	pthread_mutex_lock(&philo->data->print_lock);
	should_print = (ft_strcmp(msg, DIED) == 0
			|| check_keep_iterating(philo->data));
	if (should_print)
	{
		timestamp = get_time_ms() - philo->data->start_time;
		printf("%lu %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

long	ft_atol(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return (res);
}

/*
 * A delay function that ensures the thread wakes up at the right time.
 */
void	wait_until(uint64_t wait_time)
{
	uint64_t	start_time;

	start_time = get_time_ms();
	while ((get_time_ms() - start_time) < wait_time)
		usleep(500);
}

uint64_t	get_time_ms(void)
{
	struct timeval	tv;
	uint64_t		ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (ms);
}
