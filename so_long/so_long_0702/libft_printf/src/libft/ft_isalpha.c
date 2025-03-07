/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:17 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 14:31:34 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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

	let1 = 'd';
	let2 = 'F';
	let3 = '5';

	printf("el caracter es %c y el resultado es %i\n", let1, ft_isalpha(let1));
	printf("el caracter es %c y el resultado es %i\n", let2, ft_isalpha(let2));
	printf("el caracter es %c y el resultado es %i\n", let3, ft_isalpha(let3));
}*/
