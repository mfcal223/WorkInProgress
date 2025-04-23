/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:59:56 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/23 18:18:09 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	str1[8] = "Hello 42";
	char	*substr = ft_substr(str1, 6, 2);

	if (substr)
	{
		printf("String = %s\nSubstring = %s\n", str1, substr);
		free(substr);
	}
	else
		printf("Error. Memory allocation failed.");
	return (0);
}*/
