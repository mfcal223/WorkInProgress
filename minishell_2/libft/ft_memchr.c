/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:43:52 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 14:29:03 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main()
{
	const char str[] = "Hello 42";
	char	*found;
	char	search;

	search = 'o';
	found = ft_memchr (str, search, sizeof(str));
	if (found != NULL)
		printf("Found %c at position: %ld.\n", search, found - str);
	else
		printf("Not found %c in str.\n", search);

	search = 'x';
	found = ft_memchr (str, search, sizeof(str));
        if (found != NULL)
                printf("Found %c at position: %ld.\n", search, found - str);
        else
                printf("Not found %c in str.\n", search);
	return (0);
}*/
