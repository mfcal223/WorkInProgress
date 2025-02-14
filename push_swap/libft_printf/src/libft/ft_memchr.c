/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:19:02 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/24 09:53:08 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	let;
	unsigned char	*f;

	let = (unsigned char)c;
	f = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (f[i] == let)
			return ((void *)(&f[i]));
		i++;
	}
	return (0);
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

int main(void) 
{
    char str1[] = "Hello, world!";
    char str2[] = "This is a test string";
    char str3[] = "";
    char str4[] = "1234567890";
    char str5[] = "memchr function test";
    char str6[] = "\0hidden\0characters";
    char str7[] = "abcdefg";
    char str8[] = "another test";
    char str9[] = "yet another test";
    char str10[] = "final test case";

    return (0);
 }*/
