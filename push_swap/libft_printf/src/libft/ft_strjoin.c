/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:50:22 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/25 11:00:41 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*final;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	final = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!final)
		return (0);
	ft_strlcpy(final, s1, len_s1 + 1);
	ft_strlcat(final, s2, len_s1 + len_s2 + 1);
	return (final);
}
/*
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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ldes;
	size_t	lsrc;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	ldes = j;
	lsrc = ft_strlen(src);
	if (size == 0 || size <= ldes)
		return (lsrc + size);
	while (src[i] != '\0' && i < (size - ldes - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ldes + lsrc);
}*/
/*
int main() {
    char *result;

    // Test case 1: Normal concatenation
    result = ft_strjoin("Hello, ", "world!");
    printf("Test 1: %s\n", result); // Expected: "Hello, world!"
    free(result);

    // Test case 2: One empty string
    result = ft_strjoin("", "world!");
    printf("Test 2: %s\n", result); // Expected: "world!"
    free(result);

    result = ft_strjoin("Hello, ", "");
    printf("Test 2: %s\n", result); // Expected: "Hello, "
    free(result);

    // Test case 3: Both empty strings
    result = ft_strjoin("", "");
    printf("Test 3: %s\n", result); // Expected: ""
    free(result);

    // Test case 4: Very large strings (testing memory allocation)
    char *large_string1 = (char *)malloc(1001);
    char *large_string2 = (char *)malloc(1001);
    memset(large_string1, 'A', 1000);
    memset(large_string2, 'B', 1000);
    large_string1[1000] = '\0';
    large_string2[1000] = '\0';
    result = ft_strjoin(large_string1, large_string2);
    printf("Test 4: First 10 chars: %.10s\n", result); // Expected: "AAAAABBBB"
    printf("Test 4: Last 10 chars: %.10s\n", result + 1990); // Expected: "BBB"
    free(result);
    free(large_string1);
    free(large_string2);

    // Test case 5: Null input
    result = ft_strjoin(NULL, "world!");
    printf("Test 5: %s\n", result); // Expected: (null)

    result = ft_strjoin("Hello, ", NULL);
    printf("Test 5: %s\n", result); // Expected: (null)

    return 0;
}*/
