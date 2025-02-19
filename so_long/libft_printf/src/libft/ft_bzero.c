/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:48:21 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/23 11:15:27 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str[20] = "ASDASDASD";
	char	str2[20] = "ASDASDASD";

	ft_bzero(str, 5);
	bzero(str2, 5);
	printf("String after bzero(): %s\n", str);
	printf("test bzero: %s\n", str2);
	return (0);
}*/
