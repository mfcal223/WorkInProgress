/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:19:08 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/23 18:17:32 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	int		total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str_join = (char *) malloc (sizeof(char) * (total_len + 1));
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, s1, ft_strlen(s1) + 1);
	ft_strlcat(str_join, s2, total_len + 1);
	return (str_join);
}

/*#include <stdio.h>

int	main(void)
{
	char	str1[] = "Hello";
	char	str2[] = "42";
	char	*str_join = ft_strjoin(str1, str2);

	if (str_join)
	{
		printf("%s\n", str_join);
		free(str_join);
	}
	else
		printf("Error. Memory allocation failed.");
	return (0);
}*/
