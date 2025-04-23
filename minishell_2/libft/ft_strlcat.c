/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:46:48 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 13:36:23 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && (dest_len + i) < (size - 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (src_len + dest_len);
}

/*#include <stdio.h>

int	main(void)
{
	char dest[] = "Hello there, ";
	const char src[] = "42 Luxembourg";
	size_t	size;
	size_t	result;

	size = 20;
	printf("Source string: %s\n", src);
        printf("Destination string; %s\n", dest);

	result = ft_strlcat(dest, (char *)src, size);

	printf("Concatenated string: %s\n", dest);
	printf("Space disponible in destination: %zu\n", size);
	printf("Length of needed to create the concatenation: %zu\n", result);
	if (result > size)
		printf("Missing space to create the "
			"concatenation: %zu\n", (result-size));
	return 0;
}*/
