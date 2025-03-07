/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:39:02 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 14:44:02 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	else if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
/*	if (ft_isalpha(c) && ft_isdigit(c))
		return (c);
	else
		return (0);*/
/*
#include <stdio.h>
int	main(void)
{
	char let1;
	char let2;
	char let3;

	let1 = '3';
	let2 = 'F';
	let3 = '\n';

	printf("el caracter es %c y el resultado es %i\n", let1, ft_isalnum(let1));
	printf("el caracter es %c y el resultado es %i\n", let2, ft_isalnum(let2));
	printf("el caracter es %c y el resultado es %i\n", let3, ft_isalnum(let3));
}*/
