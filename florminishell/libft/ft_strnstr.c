/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:29:51 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 08:55:02 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[j] != '\0' && j < size)
	{
		i = 0;
		while (little[i] != '\0' && big[j + i] == little[i]
			&& (j + i) < size)
			i++;
		if (little[i] == '\0')
			return ((char *)&big[j]);
		j++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello 42";
	char	tf1[] = "42";
	char	tf2[] = "";
	char	tf3[] = "Hi";

	char	 *result = ft_strnstr(src, tf1, 20);
	printf("Source: %s\n\n", src);
        printf("To find: %s\n", tf1);
	if (result) 
	{
		printf("Found: %s\n", result);
		printf("Pointer address of source: %p\n", result);
	} 
	else 
	{
		printf("Not found\n");
		printf("Pointer value NULL %p\n", result);
	}

	result = ft_strnstr(src, tf2, 20);
        printf("\n");
	printf("To find: %s\n", tf2);
	if (result) 
        {
                printf("Found: %s\n", result);
		printf("Pointer address of source: %p\n", result);
        }
        else
        {
                printf("Not found\n");
		printf("Pointer value NULL %p\n", result);
	}

        result = ft_strnstr(src, tf3, 20);
        printf("\n");
        printf("To find: %s\n", tf3);
	if (result)
        {
                printf("Found: %s\n", result);
		printf("Pointer address of source: %p\n", result);
        }
        else
        {
                printf("Not found\n");
		printf("Pointer value NULL %p\n", result);
        }
}*/
