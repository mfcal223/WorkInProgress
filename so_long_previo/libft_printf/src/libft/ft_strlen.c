/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:56:00 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/21 16:09:10 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/* //#include <stddef.h>
#include <stdio.h>

int	main(void)
{
	char	str[50] = "500 miles";
	int	rdo;

	ft_strlen(str);
	rdo = ft_strlen(str);
	printf("the string lenght is %d\n", rdo);
	return (0);
}*/
