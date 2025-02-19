/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:02:33 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/22 11:18:20 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*var;

	var = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			var = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (var);
}
/*
int	main(void)
{
	const char	*str = "";
	char	c = 'h';
	char	*result;

	result = ft_strrchr(str, c);
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
