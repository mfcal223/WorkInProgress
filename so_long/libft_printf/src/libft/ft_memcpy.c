/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:22:36 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/23 11:41:36 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dupdest;
	unsigned char	*dupsrc;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	dupdest = (unsigned char *)dst;
	dupsrc = (unsigned char *)src;
	while (i < n)
	{
		dupdest[i] = dupsrc[i];
		i++;
	}
	return (dst);
}
/*
int main ()
{
	const char src[50] = "hipopotamo";
	char dest[50];
	size_t	len;

	len = 7;	
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, len);
	printf("After ft_memcpy dest = %s\n", dest);
	return(0);
}*/
