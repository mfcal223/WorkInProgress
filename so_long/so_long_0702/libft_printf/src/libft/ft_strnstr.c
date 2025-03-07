/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:33:54 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/22 12:14:13 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *sh, const char *sn, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (sn[0] == '\0')
		return ((char *) sh);
	while (sh[i] && i < len)
	{
		j = 0;
		while (sn[j] && sh[i + j] == sn[j] && (i + j) < len)
		{
			j++;
		}
		if (sn[j] == '\0')
			return ((char *)&sh[i]);
		i++;
	}
	return (0);
}
