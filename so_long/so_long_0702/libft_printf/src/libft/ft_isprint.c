/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:03:36 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 15:05:57 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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

	let1 = 3;
	let2 = 'F';
	let3 = '5';

	printf("el caracter es %c y el resultado es %i\n", let1, ft_isprint(let1));
	printf("el caracter es %c y el resultado es %i\n", let2, ft_isprint(let2));
	printf("el caracter es %c y el resultado es %i\n", let3, ft_isprint(let3));
}*/
