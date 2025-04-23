/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:04:51 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/23 15:43:52 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main()
{
	int	array1[] = {0, 4, 2};
	int	array2[] = {0, 42};
	int	comp;

	comp = ft_memcmp(array1, array2, 2 * sizeof(int));
	printf("Compare array1 to array2. memcmp = %d\n", comp);

	comp = ft_memcmp(array2, array1, 2 * sizeof(int));
        printf("Compare array2 to array1. memcmp = %d\n", comp);

	comp = ft_memcmp(array2, array2, 2 * sizeof(int));
        printf("Compare array2 to array2. memcmp = %d\n", comp);
}*/
