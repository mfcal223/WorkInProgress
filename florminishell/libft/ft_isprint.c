/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:30:14 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:20:50 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int	main()
{
	char	c1;
	char	c2;
	char	c3;
	char	c4;
	char	c5;

	c1 = 'h';
	c2 = '4';
	c3 = '?';
	c4 = ' ';
	c5 = '\t';

	printf("C1 = %c. ft_isprint returns %d.\n", c1, ft_isprint(c1));
	printf("C2 = %c. ft_isprint returns %d.\n", c2, ft_isprint(c2));
	printf("C3 = %c. ft_isprint returns %d.\n", c3, ft_isprint(c3));
	printf("C4 = %c. ft_isprint returns %d.\n", c4, ft_isprint(c4));
	printf("C5 = %c. ft_isprint returns %d.\n", c5, ft_isprint(c5));
}*/
