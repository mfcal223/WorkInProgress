/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:17:42 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 10:36:42 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	pointer = malloc (nmemb * size);
	if (!pointer)
		return (NULL);
	ft_memset(pointer, 0, nmemb * size);
	return (pointer);
}

/*#include <stdio.h>

int	main(void)
{
	int	*array;
	size_t	n_elements = 4;
	size_t	i;

	array = (int *) ft_calloc (n_elements, sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation error.\n");
		return (1);
	}
	i = 0;
	while (i < n_elements)
	{
		printf("Array = [%zu] = %d\n", i, array[i]);
		i++;
	}
	free (array);
	return (0);
}*/
