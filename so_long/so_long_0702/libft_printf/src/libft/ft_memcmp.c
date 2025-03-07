/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:27:33 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/24 10:38:34 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (0);
}
/*
int main(void) {
	char str1[] = "abcdef";
    char str2[] = "abcdeg";
    char str3[] = "abcdef";
    char str4[] = "abcdefg";
    char str5[] = "ABCDEF";
    char str6[] = "abcdef";
    char str7[] = "";
    char str8[] = "";
//    char str9[] = "abcdef";
    char str10[] = "abcdeF";

    // Test case 1: Compare equal strings
    printf("Test 1: %d\n", ft_memcmp(str1, str3, 6));
    // Test case 2: Compare strings with one different character
    printf("Test 2: %d\n", ft_memcmp(str1, str2, 6));
    // Test case 3: Compare strings with different lengths
    printf("Test 3: %d\n", ft_memcmp(str1, str4, 7));
    // Test case 4: Compare case-sensitive strings
    printf("Test 4: %d\n", ft_memcmp(str1, str5, 6));
    // Test case 5: Compare empty strings
    printf("Test 5: %d\n", ft_memcmp(str7, str8, 1));
    // Test case 6: Compare up to length zero
    printf("Test 6: %d\n", ft_memcmp(str1, str6, 0));
    // Test case 7: Compare with larger n than string length
    printf("Test 7: %d\n", ft_memcmp(str1, str6, 10));
    // Test case 8: Compare partially different strings
    printf("Test 8: %d\n", ft_memcmp(str1, str10, 6));
    // Test case 9: Compare single character
    printf("Test 9: %d\n", ft_memcmp("a", "a", 1));
    // Test case 10: Compare first character different
    printf("Test 10: %d\n", ft_memcmp("a", "b", 1));
	printf ("%i\n", ft_memcmp("test\200", "test\0", 6));	
    return (0);
}*/
