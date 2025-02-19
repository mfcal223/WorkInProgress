/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:47:57 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 14:50:37 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int     main(void)
{
        char let1;
        char let2;
        char let3;

        let1 = '3';
        let2 = 'F';
        let3 = '\n';

        printf("es %c y el resultado es %i\n", let1, ft_isascii(let1));
        printf("es %c y el resultado es %i\n", let2, ft_isascii(let2));
        printf("es %c y el resultado es %i\n", let3, ft_isascii(let3));
}*/
