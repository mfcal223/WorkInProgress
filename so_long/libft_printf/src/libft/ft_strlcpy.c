/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:53:36 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/22 09:04:03 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	j = 0;
	if (dstsize == 0)
		return (i);
	else
	{
		while ((j < dstsize - 1) && (src[j] != '\0'))
		{
			dst[j] = src[j];
			j++;
		}
	}
	dst[j] = '\0';
	return (i);
}
/*
int	main(void)
{
	char	o[20] = "yo me quedo";
	char	f[20] = "esto se va ";
	size_t	n;

	n = 0;
	printf("length is %li and says %s\n", ft_strlcpy(f, o, n), f);
	return (0);
}*/
