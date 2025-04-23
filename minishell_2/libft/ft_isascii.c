/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:04:59 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:20:16 by mpiantan         ###   ########.fr       */
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

/*#include <stdio.h>
int	main()
{
	char	c1;
	char	c2;
	char	c3;

	c1 = 'h';
	c2 = '4';
	c3 = '?';

	printf("C1 = %c. ft_isascii returns %d.\n", c1, ft_isascii(c1));
	printf("C2 = %c. ft_isascii returns %d.\n", c2, ft_isascii(c2));
	printf("C3 = %c. ft_isascii returns %d.\n", c3, ft_isascii(c3));
}*/
