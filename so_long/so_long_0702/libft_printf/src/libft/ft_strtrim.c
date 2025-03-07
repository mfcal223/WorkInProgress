/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:23:52 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/25 12:47:06 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	ini;
	size_t	fin;
	size_t	len_copy;
	char	*copy;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	ini = 0;
	while (ini < len && ft_strchr(set, s1[ini]) != 0)
		ini++;
	fin = len;
	while (fin > ini && ft_strchr(set, s1[fin - 1]) != 0)
		fin--;
	len_copy = fin - ini;
	copy = (char *)malloc((len_copy + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1 + ini, len_copy + 1);
	return (copy);
}
/*
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
	{
		i++;
	}
	j = 0;
	if (dstsize == 0)
		return (i);
	else
	{
		while ((j < dstsize - 1) && (src[j] != '\0'))
		{
			dst[j] = src[j];
			j++;
		}
	}
	dst[j] = '\0';
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
*/
/*
int main() {
    char *result;

    // Test case 1: Normal trimming
    result = ft_strtrim("   Hello, world!   ", " ");
    printf("Test 1: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 2: Trimming characters from both ends
    result = ft_strtrim("$$$Hello, world!$$$", "$");
    printf("Test 2: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 3: Trimming with characters inside the string
    result = ft_strtrim("$$$Hello, $$$world!$$$", "$");
    printf("Test 3: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 4: No characters to trim
    result = ft_strtrim("Hello, world!", "$ ");
    printf("Test 4: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 5: Empty string
    result = ft_strtrim("", " $");
    printf("Test 5: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 6: Set is empty
    result = ft_strtrim("   Hello, world!   ", "");
    printf("Test 6: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 7: Both string and set are empty
    result = ft_strtrim("", "");
    printf("Test 7: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 8: String with special characters in set
    result = ft_strtrim("!!**Hello, world!!**", "!*");
    printf("Test 8: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 9: Only characters from set in string
    result = ft_strtrim("AAAAA", "A");
    printf("Test 9: '%s'\n", result ? result : "NULL");
    free(result);

    // Test case 10: Null input
    result = ft_strtrim(NULL, "$");
    printf("Test 10: '%s'\n", result ? result : "NULL");

    result = ft_strtrim("$$$Hello, world!$$$", NULL);
    printf("Test 11: '%s'\n", result ? result : "NULL");

    return 0;
}*/
