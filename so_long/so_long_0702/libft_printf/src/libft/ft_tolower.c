/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:39:12 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 15:40:22 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
	printf("la letra es %c y rdo es %i\n", let1, ft_tolower(let1));
	printf("la letra es %c y rdo es %i\n", let2, ft_tolower(let2));
	printf("la letra es %c y rdo es %i\n", let3, ft_tolower(let3));
}*/
