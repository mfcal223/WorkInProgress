/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:34:04 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 15:39:01 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
#include <stdio.h>
int	main(void)
{       
	char let1;
	char let2;
	char let3;

	let1 = 'i';
	let2 = 'F';
	let3 = '5';
	printf("la letra es %c y rdo es %i\n", let1, ft_toupper(let1));
	printf("la letra es %c y rdo es %i\n", let2, ft_toupper(let2));
	printf("la letra es %c y rdo es %i\n", let3, ft_toupper(let3));
}*/
