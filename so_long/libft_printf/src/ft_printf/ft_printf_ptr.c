/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:47:19 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/19 10:47:32 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_ptr_aide(unsigned long long nbr, char *base, size_t *i)
{
	unsigned long long	num;

	num = nbr;
	if (num >= 16)
	{
		ft_print_ptr_aide(num / 16, base, i);
		ft_print_ptr_aide(num % 16, base, i);
	}
	else
		ft_print_char(base[num], i);
}

void	ft_print_ptr(void *ptr, size_t *i)
{
	unsigned long long	addr;
	char				*base;

	base = "0123456789abcdef";
	addr = (unsigned long long) ptr;
	if (addr == 0)
	{
		write(1, "(nil)", 5);
		*i += 5;
		return ;
	}
	write(1, "0x", 2);
	(*i) += 2;
	ft_print_ptr_aide(addr, base, i);
}
/*
comments:
- addr = (unsigned long long) ptr; // adapt data type pter address 
- write(1, "0x", 2);// Print pointer prefix

PARA UN MAIN:	
	
	// Test pointers
	int n = 42;
	ft_printf("Pointer: %p\n", &n);
	printf("Pointer: %p\n", &n);

	// Additional test cases from Tripouille
	ft_printf(" My function %p \n", (void*)-1);
	printf("printf %p \n", (void*)-1);

	ft_printf(" My function %p \n", (void*)1);
	printf("printf %p \n", (void*)1);

	ft_printf("My function %p \n", (void*)15);
	printf("printf %p \n", (void*)15);

	ft_printf("My function %p \n", (void*)16);
	printf("printf %p \n", (void*)16);

	ft_printf(" My function%p \n", (void*)17);
	printf("printf %p \n", (void*)17);

	ft_printf("My function %p %p \n", (void*)LONG_MIN, (void*)LONG_MAX);
	printf("printf %p %p \n", (void*)LONG_MIN, (void*)LONG_MAX);

	ft_printf("My function %p %p \n", (void*)INT_MIN, (void*)INT_MAX);
	printf("printf %p %p \n", (void*)INT_MIN, (void*)INT_MAX);

	ft_printf("My function %p %p \n", (void*)ULONG_MAX, (void*)-ULONG_MAX);
	printf("printf %p %p \n", (void*)ULONG_MAX, (void*)-ULONG_MAX);

	ft_printf("My function %p %p \n", (void*)0, (void*)0);
	printf("printf %p %p \n", (void*)0, (void*)0);
*/
