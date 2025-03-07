/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:33:23 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 14:38:29 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
/*
#include <stdio.h>
int	main(void)
{       
	char let1;
	char let2;
	char let3;

	let1 = '3';
	let2 = 'F';
	let3 = '5';

	printf("el caracter es %c y el resultado es %i\n", let1, ft_isdigit(let1));
	printf("el caracter es %c y el resultado es %i\n", let2, ft_isdigit(let2));
	printf("el caracter es %c y el resultado es %i\n", let3, ft_isdigit(let3));
}*/
