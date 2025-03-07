/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:45:39 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/19 10:45:53 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int num, size_t *i)
{
	if (num == -2147483648)
	{
		ft_print_char('-', i);
		ft_print_char('2', i);
		ft_print_nbr(147483648, i);
	}
	else if (num < 0)
	{
		ft_print_char('-', i);
		num *= -1;
		ft_print_nbr(num, i);
	}
	else if (num > 9)
	{
		ft_print_nbr(num / 10, i);
		ft_print_nbr(num % 10, i);
	}
	else
		ft_print_char(num + '0', i);
}
/*
comments:
 //alt write(fd, "-2147483648", 11);

MAIN()
	// Test integers from tripouille
	ft_printf(" My function %i \n", 0);
	printf("printf %i \n", 0);

	ft_printf(" My function %i \n", -1);
	printf("printf %i \n", -1);

	ft_printf(" My function %i \n", 1);
	printf("printf %i \n", 1);

	ft_printf(" My function %i \n", 9);
	printf("printf %i \n", 9);

	ft_printf(" My function %i \n", 10);
	printf("printf %i \n", 10);

	ft_printf(" My function %i \n", 11);
	printf("printf %i \n", 11);

	ft_printf(" My function %i \n", 15);
	printf("printf %i \n", 15);

	ft_printf(" My function %i \n", 16);
	printf("printf %i \n", 16);

	ft_printf(" My function %i \n", 17);
	printf("printf %i \n", 17);

	ft_printf(" My function %i \n", 99);
	printf("printf %i \n", 99);

	ft_printf(" My function %i \n", 100);
	printf("printf %i \n", 100);

	ft_printf(" My function %i \n", 101);
	printf("printf %i \n", 101);

	ft_printf(" My function %i \n", -9);
	printf("printf %i \n", -9);

	ft_printf(" My function %i \n", -10);
	printf("printf %i \n", -10);

	ft_printf(" My function %i \n", -11);
	printf("printf %i \n", -11);

	ft_printf(" My function %i \n", -14);
	printf("printf %i \n", -14);

	ft_printf(" My function %i \n", -15);
	printf("printf %i \n", -15);

	ft_printf(" My function %i \n", -16);
	printf("printf %i \n", -16);

	ft_printf(" My function %i \n", -99);
	printf("printf %i \n", -99);

	ft_printf(" My function %i \n", -100);
	printf("printf %i \n", -100);

	ft_printf(" My function %i \n", -101);
	printf("printf %i \n", -101);

	ft_printf(" My function %i \n", INT_MAX);
	printf("printf %i \n", INT_MAX);

	ft_printf(" My function %i \n", INT_MIN);
	printf("printf %i \n", INT_MIN);

	ft_printf(" My function %li \n", LONG_MAX);
	printf("printf %li \n", LONG_MAX);

	ft_printf(" My function %li \n", LONG_MIN);
	printf("printf %li \n", LONG_MIN);

	ft_printf(" My function %u \n", UINT_MAX);
	printf("printf %u \n", UINT_MAX);

	ft_printf(" My function %lu \n", ULONG_MAX);
	printf("printf %lu \n", ULONG_MAX);

	ft_printf(" My function %lli \n", 9223372036854775807LL);
	printf("printf %lli \n", 9223372036854775807LL);
*/
