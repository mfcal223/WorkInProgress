/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:37:47 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 10:54:55 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(const char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, (char *)&s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void test_func(unsigned int i, char *c) 
{
    *c = *c + i;
}*/
/*
int main(void) {
    char str1[] = "abc";
    char str2[] = "123";
    char str3[] = "Hello";
    char str4[] = "Test";
    char str5[] = "XYZ";

    ft_striteri(str1, test_func);
    printf("Test 1: %s\n", str1); // Expected: ace (a+0, b+1, c+2)

    ft_striteri(str2, test_func);
    printf("Test 2: %s\n", str2); // Expected: 135 (1+0, 2+1, 3+2)

    ft_striteri(str3, test_func);
    printf("Test 3: %s\n", str3); // Expected: Hfnos (H+0, e+1, l+2, l+3, o+4)

    ft_striteri(str4, test_func);
    printf("Test 4: %s\n", str4); // Expected: Tfuw (T+0, e+1, s+2, t+3)

    ft_striteri(str5, test_func);
    printf("Test 5: %s\n", str5); // Expected: XY\

    return (0);
}*/
