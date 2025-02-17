/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 08:42:42 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/17 10:41:38 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	sum;
	int		k;

	i = 0;
	k = 0;
	sign = 1;
	sum = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	while ((str[i] == '+' || str[i] == '-') && k == 0)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		k++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sign * sum);
}
