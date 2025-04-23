/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:40:26 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/23 15:04:40 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	char	str[20] = "Hello 42";
	char	str1[20] = "Hola 42";

	ft_memmove(str + 8, str, 2);
	printf("Non-overlapping memmove = %s\n", str);

	ft_memmove(str1 + 5, str1, 7);
	printf("Overlapping memmove = %s\n", str1);

	return (0);
}*/
