/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:37:12 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 14:08:06 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char	*s = "Hello 42";
	int	c;

	c = 'l';
	printf("String: %s, c: %c, strchr: %s\n", s, c, ft_strchr(s, c));

	c = 'x';
	printf("String: %s, c: %c, strchr: %s\n", s, c, ft_strchr(s, c));

	c = '\0';
	printf("String: %s, c: '\\0', strchr: %p\n", s, ft_strchr(s, c));
}*/
