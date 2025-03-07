/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:27:07 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/22 10:59:33 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*str = "holas";
	char	c = 'k';
	char	*result;

	result = ft_strchr(str, c);
	if (result)
	{
		printf("encontré la letra %c\n", *result);
	}
	else
	{
		printf("no encontré nada\n");
	}
	return (0);
}*/
