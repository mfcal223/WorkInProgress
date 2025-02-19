/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:10:06 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/23 12:52:56 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int	main(void)
{
	char	str1[20] = "abcdefghjjkl";
	char	str2[20] = "abcd";
	unsigned int	n;
	int	ret;

	n = 6;
	ret = ft_strncmp(str1, str2, n);
	printf("%s and %s = %d\n", str1, str2, ret);
	printf ("%i\n", ft_strncmp("test\200", "test\0", 6));
	return (0);
}*/
