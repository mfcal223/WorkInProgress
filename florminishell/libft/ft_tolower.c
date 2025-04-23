/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:49:28 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:21:09 by mpiantan         ###   ########.fr       */
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

	printf("C1 = %c. ft_tolower returns %c.\n", c1, ft_tolower(c1));
	printf("C2 = %c. ft_tolower returns %c.\n", c2, ft_tolower(c2));
	printf("C3 = %c. ft_tolower returns %c.\n", c3, ft_tolower(c3));
	printf("C4 = %c. ft_tolower returns %c.\n", c4, ft_tolower(c4));
	printf("C5 = %c. ft_tolower returns %c.\n", c5, ft_tolower(c5));
	printf("C6 = %c. ft_tolower returns %c.\n", c6, ft_tolower(c6));
}*/
