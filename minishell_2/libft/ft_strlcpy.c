/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:53:36 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 13:33:31 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

/*#include <stdio.h>

int	main(void)
{
	char dest[10];
	const char *src = "Hello 42!";
	size_t result;

	result = ft_strlcpy(dest, (char *)src, 8);

	printf("Source string: %s\n", src);
	printf("Copied string: %s\n", dest);
	printf("Length of source string: %zu\n", result);

	return 0;
}*/
