/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:30:51 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/24 16:03:09 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_check_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	ft_find_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_check_set(s1[i], set))
		i++;
	return (i);
}

int	ft_find_end(const char *s1, const char *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_check_set(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	len = end - start + 1;
	if (start > end)
		return (ft_strdup(""));
	trimmed_s = (char *) malloc (sizeof(char) * (len + 1));
	if (!trimmed_s)
		return (NULL);
	ft_strlcpy(trimmed_s, s1 + start, len + 1);
	return (trimmed_s);
}

/*#include <stdio.h>

int	main()
{
	char	*str = "+--+-+Hello 42+--";
	char	*charset = "-+";
	char	*trimmed_str;

	printf("Str to be trimmed: %s\nCharset to delete: %s\n", str, charset);
	trimmed_str = ft_strtrim(str, charset);
	printf("Trimmed str: %s\n", trimmed_str);
	free(trimmed_str);

	str = "";
	printf("\nStr to be trimmed: %s\nCharset to delete: %s\n", str, charset);
	trimmed_str = ft_strtrim(str, charset);
	printf("Trimmed str: %s (Empty str)\n", trimmed_str);
	free(trimmed_str);

	str = "Hello 42";
	printf("\nStr to be trimmed: %s\nCharset to delete: %s\n", str, charset);
	trimmed_str = ft_strtrim(str, charset);
	printf("Trimmed str: %s (No trim)\n", trimmed_str);
	free(trimmed_str);

	str = "+-++";
	printf("\nStr to be trimmed: %s\nCharset to delete: %s\n", str, charset);
	trimmed_str = ft_strtrim(str, charset);
	printf("Trimmed str: %s (Full trim)\n", trimmed_str);
	free(trimmed_str);

	return (0);
}*/
