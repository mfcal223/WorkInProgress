/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:42:42 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/06 09:57:35 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	sum;
	int	k;

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
/*
int	main(void)
{
	char	s[50] = " 67 8 a3";

	printf("atoi : %i\n", atoi(s));
	printf("ft_atoi %i\n", ft_atoi(s));
}*/
