/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:15:21 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/22 09:25:28 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ldes;
	size_t	lsrc;

	i = 0;
	ldes = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if (size == 0 || size <= ldes)
		return (lsrc + size);
	j = ldes;
	while (src[i] != '\0' && i < (size - ldes - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ldes + lsrc);
}

/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char dest[15];
    memset(dest, 'r', 15); // Llenar dest con 'r'
    dest[14] = '\0'; // Asegúrate de que esté correctamente terminado

    printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
    write(1, "\n", 1);
    write(1, dest, 15); // Debe imprimir "rrrrrrrrrrrrrrr"
    return 0;
}*/
