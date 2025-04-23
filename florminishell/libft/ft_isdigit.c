/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:34:32 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/21 16:20:33 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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

	printf("C1 = %c. ft_isdigit returns %d.\n", c1, ft_isdigit(c1));
	printf("C2 = %c. ft_isdigit returns %d.\n", c2, ft_isdigit(c2));
	printf("C3 = %c. ft_isdigit returns %d.\n", c3, ft_isdigit(c3));
}*/
