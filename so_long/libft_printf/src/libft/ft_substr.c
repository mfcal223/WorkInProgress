/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:49:34 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/25 10:25:21 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	copy_len;
	char	*copy;

	if (!s)
		return (0);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	copy_len = len;
	if (start + len > str_len)
		copy_len = str_len - start;
	copy = (char *)malloc((copy_len + 1) * sizeof(char));
	if (!copy)
		return (0);
	ft_strlcpy(copy, s + start, copy_len + 1);
	copy[copy_len] = '\0';
	return (copy);
}
/*
static char	*ft_strdup2(const char *s1)
{
	size_t	i;
	char	*s2;

	s2 = (char *) malloc(ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}*/
/*size_t	ft_strlen(const char *s)
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
*/
/*
#include <stdio.h>
int main() {
    char *result;

    // Test case 1: Normal substring
    result = ft_substr("Hello, world!", 7, 5);
    printf("Test 1: %s\n", result); // Expected: "world"
    free(result);
    // Test case 2: Start index beyond string length
    result = ft_substr("Hello, world!", 20, 5);
    printf("Test 2: %s\n", result); // Expected: ""
    free(result);
    // Test case 3: Length beyond string length
    result = ft_substr("Hello, world!", 7, 20);
    printf("Test 3: %s\n", result); // Expected: "world!"
    free(result);
    // Test case 4: Length of 0
    result = ft_substr("Hello, world!", 7, 0);
    printf("Test 4: %s\n", result); // Expected: ""
    free(result);
    // Test case 5: Start at 0, full length of string
    result = ft_substr("Hello, world!", 0, 13);
    printf("Test 5: %s\n", result); // Expected: "Hello, world!"
    free(result);
    // Test case 6: Empty string
    result = ft_substr("", 0, 5);
    printf("Test 6: %s\n", result); // Expected: ""
    free(result);
    // Test case 7: String with special characters
    result = ft_substr("!@#$%^&*()_+", 2, 5);
    printf("Test 7: %s\n", result); // Expected: "#$%^&"
    free(result);
    // Test case 8: Substring of single character string
    result = ft_substr("a", 0, 1);
    printf("Test 8: %s\n", result); // Expected: "a"
    free(result);
    // Test case 9: Substring starting at end of string
    result = ft_substr("abcdef", 6, 2);
    printf("Test 9: %s\n", result); // Expected: ""
    free(result);
    // Test case 10: Start in the middle, length goes beyond string
    result = ft_substr("Hello, world!", 5, 50);
    printf("Test 10: %s\n", result); // Expected: ", world!"
    free(result);
    return (0);
}*/
