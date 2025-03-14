/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:39:56 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/14 14:19:45 by mcalciat         ###   ########.fr       */
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



