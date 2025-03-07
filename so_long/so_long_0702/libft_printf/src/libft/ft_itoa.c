/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:05:54 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/28 13:27:25 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count ++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	number;
	int		leng;

	number = n;
	leng = ft_digit_count(n);
	s = ft_calloc((leng + 1), sizeof(char));
	if (!s)
		return (0);
	s[leng] = '\0';
	if (number < 0)
	{
		s[0] = '-';
		number = -number;
	}
	while (leng > 0 && s[leng - 1] != '-')
	{
		s[leng - 1] = (number % 10) + 48;
		number /= 10;
		leng--;
	}
	return (s);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int	test_cases[] = {0, -123, 123, INT_MAX, INT_MIN, -214748364, 214748364};
	char	*result;
	int	i;

	i = 0;
    	while (i++ < 11)
	{
	        result = ft_itoa(test_cases[i]);
        	printf("ft_itoa(%d) = %s\n", test_cases[i], result);
        	free(result);
	}
	return (0);
}*/
