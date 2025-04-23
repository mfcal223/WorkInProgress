/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:06 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/22 17:05:38 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello 42";
	size_t	i;
	
	printf("Original string: %s.\n", str);
	ft_bzero (str, 5);
	printf("Modified string: ");
	i = 0;
	while (i < sizeof(str))
	{
		if (str[i] == '\0')
			printf("\\0");
		else
			printf("%c ", str[i]);
		i++;
	}
	printf("\n");

	return (0);
}*/
