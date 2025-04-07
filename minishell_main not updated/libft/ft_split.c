/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:21:44 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/24 09:55:26 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_count_words(const char *str, char separator)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != separator && i == 0)
		{
			i = 1;
			count++;
		}
		else if (*str == separator)
			i = 0;
		str++;
	}
	return (count);
}

char	*ft_copy_words(const char *start, const char *end)
{
	char	*word;
	int		len;

	len = end - start;
	word = (char *) malloc (sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		s_word;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s_word = -1;
	split = ft_calloc ((ft_count_words(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && s_word >= 0)
		{
			split[j++] = ft_copy_words(s + s_word, s + i);
			if (!split[j - 1])
				return (ft_free (split), (NULL));
			s_word = -1;
		}
		i++;
	}
	return (split);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str = "Hello-there-42";
	char	separator = '-';
	char	**split;
	int	i;

	i = 0;
	printf("Origin str: %s\nSeparator: %c\n", str, separator);

	split = ft_split(str, separator);
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
