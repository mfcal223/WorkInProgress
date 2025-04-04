/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:21:12 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:19:55 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int	main(void)
{
	char	c1;
	char	c2;
	char	c3;

	c1 = 'h';
	c2 = '4';
	c3 = '?';

	printf("C1 = %c. ft_isalpha returns %d.\n", c1, ft_isalpha(c1));
	printf("C2 = %c. ft_isalpha returns %d.\n", c2, ft_isalpha(c2));
	printf("C3 = %c. ft_isalpha returns %d.\n", c3, ft_isalpha(c3));
}*/
