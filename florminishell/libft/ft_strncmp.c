/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:08:00 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 08:56:43 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>

int 	main(void)
{
	char *s1 = "Hello 42 Luxembourg";
	char *s2 = "Hello Pisciner";

	printf("Comparing first 5 characters: %d\n", ft_strncmp(s1, s2, 5));
	printf("Comparing first 8 characters: %d\n", ft_strncmp(s1, s2, 8));
	printf("Comparing first 3 characters: %d\n", ft_strncmp(s1, "hi!" , 3));
	printf("Comparing different strings: %d\n", ft_strncmp("abc", "abd", 3));

	return (0);
}*/
