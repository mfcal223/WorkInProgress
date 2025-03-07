/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:37:44 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/25 16:38:20 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	const char	*end;

	start = *s;
	while (*start && *start == c)
		start++;
	end = start;
	while (*end && *end != c)
		end++;
	if (start == end)
		return (NULL);
	*s = end;
	return (ft_strndup(start, end - start));
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
			if (!*s)
				break ;
		}
		s++;
	}
	return (count);
}

static void	free_split(char **res, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(res[j]);
		j++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	int		word_num;
	char	**word_array;
	int		i;

	if (!s)
		return (NULL);
	word_num = count_words(s, c);
	word_array = malloc((word_num + 1) * sizeof(char *));
	if (!word_array)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_array[i] = get_next_word(&s, c);
			if (!word_array[i])
				return (free_split(word_array, i), (NULL));
			i++;
		}
		else
			s++;
	}
	word_array[i] = NULL;
	return (word_array);
}
/*
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*str = "Hello-there-42";
	char	separator = '-';
	char	**split;
	int	i = 0;

	printf("Origin str: %s\nSeparator: %c\n", str, separator);

	split = ft_split(str, separator);
	if (!split)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}

	printf("Split str:\n");
	while (split[i] != NULL)
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}*/
