/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:15:03 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/22 16:35:29 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "Hello 42";
	
	printf("Original string: %s.\n", str);
	ft_memset (str, '*', 5);
	printf("Modified string: %s.\n", str);

	return (0);
}*/
