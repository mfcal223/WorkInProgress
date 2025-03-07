/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:49 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/19 10:46:54 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_print_hexa(unsigned int nbr, char *base, size_t *i)
{
	unsigned long	len;

	len = ft_length(base);
	if (nbr == 0)
	{
		*i += write(1, "0", 1);
		return ;
	}
	if (nbr >= len)
		ft_print_hexa(nbr / len, base, i);
	(*i) += write(1, &base[nbr % len], 1);
}
