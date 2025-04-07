/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:00:35 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:21:25 by mpiantan         ###   ########.fr       */
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

/*#include <stdio.h>
int	main()
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;
	char	c5;
	char	c6;

	c1 = 'h';
	c2 = '4';
	c3 = '?';
	c4 = ' ';
	c5 = '\t';
	c6 = 'P';

	printf("C1 = %c. ft_toupper returns %c.\n", c1, ft_toupper(c1));
	printf("C2 = %c. ft_toupper returns %c.\n", c2, ft_toupper(c2));
	printf("C3 = %c. ft_toupper returns %c.\n", c3, ft_toupper(c3));
	printf("C4 = %c. ft_toupper returns %c.\n", c4, ft_toupper(c4));
	printf("C5 = %c. ft_toupper returns %c.\n", c5, ft_toupper(c5));
	printf("C6 = %c. ft_toupper returns %c.\n", c6, ft_toupper(c6));
}*/
