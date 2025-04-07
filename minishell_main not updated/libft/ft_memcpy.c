/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:13:13 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/22 17:29:52 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	char	src[] = "Hello 42";
	char	dest[10];

	ft_memcpy(dest, src, 8);
	dest[8] = '\0';

	printf("src = %s\n", src);
	printf("dest after memcpy = %s\n", dest);
	return (0);
}*/
