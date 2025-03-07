/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:12:55 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/24 12:22:06 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
}
/* 
#include <stdlib.h>
#include <stdio.h>
(de volver a test, hay que poner esto arriba de ft_strdup)
size_t  ft_strlen(const char *s)
{
        size_t  i;

        i = 0;
        while (s[i])
        {
                i++;
        }
        return (i);
}

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "";
    char str3[] = "a";
    char str4[] = "1234567890";
    char str5[] = "special characters !@#$%^&*()";
    char *dup;

    // Test case 1: Normal string
    dup = ft_strdup(str1);
    printf("Test 1: Original: %s, Duplicated: %s\n", str1, dup);
    free(dup);

    // Test case 2: Empty string
    dup = ft_strdup(str2);
    printf("Test 2: Original: %s, Duplicated: %s\n", str2, dup);
    free(dup);

    // Test case 3: Single character string
    dup = ft_strdup(str3);
    printf("Test 3: Original: %s, Duplicated: %s\n", str3, dup);
    free(dup);

    // Test case 4: Numeric characters
    dup = ft_strdup(str4);
    printf("Test 4: Original: %s, Duplicated: %s\n", str4, dup);
    free(dup);

    // Test case 5: Special characters
    dup = ft_strdup(str5);
    printf("Test 5: Original: %s, Duplicated: %s\n", str5, dup);
    free(dup);

    return (0);
}*/
