/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:05:53 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/24 18:41:06 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	to_uppercase(unsigned int index, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

#include <stdio.h>

int	main()
{
	char	str[] = "Hello 42";

	printf("Str = %s\nFt = touppercase\n", str);
	ft_striteri(str, to_uppercase);
	printf("Result = %s\n", str);

	return (0);
}*/
