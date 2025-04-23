/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:06:07 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 14:08:47 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_matched;

	last_matched = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_matched = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (last_matched);
}

/*#include <stdio.h>

int	main(void)
{
	char	*s = "Hello 42";
	int	c;

	c = 'l';
	printf("String: %s, c: %c, strrchr: %s\n", s, c, ft_strrchr(s, c));

	c = 'x';
	printf("String: %s, c: %c, strrchr: %s\n", s, c, ft_strrchr(s, c));

	c = '\0';
	printf("String: %s, c: '\\0', strrchr: %p\n", s, ft_strrchr(s, c));

}*/
