/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:43:04 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 15:19:50 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		len;
	int		i;

	len = ft_strlen(s);
	i = 0;
	cp = (char *) malloc (sizeof(char) * (len + 1));
	if (!cp)
		return (NULL);
	while (s[i] != '\0')
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str = "Hello there 42!";
	char	*cp_str;

	cp_str = ft_strdup(str);
	if (cp_str != NULL)
	{
		printf ("Source is: %s. Copy is %s.\n", str, cp_str);
		free(cp_str);
	}
	else
		printf ("Error in memory allocation.\n");
	return (0);
}*/
