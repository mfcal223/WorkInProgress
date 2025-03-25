/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:43:30 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:19:37 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
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

	printf("C1 = %c. ft_isalnum returns %d.\n", c1, ft_isalnum(c1));
	printf("C2 = %c. ft_isalnum returns %d.\n", c2, ft_isalnum(c2));
	printf("C3 = %c. ft_isalnum returns %d.\n", c3, ft_isalnum(c3));
}*/
