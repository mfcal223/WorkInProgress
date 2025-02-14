/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:10:57 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/23 16:44:41 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dst);
}
/*
int	main(void)
{
	char src[50] = "0123456789";
	char src1[50] = "0123456789";
	char src2[50] = "0123456789";
	size_t	len;

	len = 4;
	printf("Before memmove dest = %s\n", src);
	ft_memmove(src + 2, src, len);
	printf("After ft_memmove dest = %s\n", src);
	ft_memmove(src1, src1 + 2 , len);
	printf("After ft_memmove dest = %s\n", src1);
	ft_memmove(src2 + 2, src2 +1, len);
	printf("After ft_memmove dest = %s\n", src2);
	return(0);
}*/
