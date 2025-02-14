/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:45:06 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/19 10:45:28 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(char *str, size_t *i)
{
	size_t	j;

	j = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*i += 6;
		return ;
	}
	while (str[j])
	{
		ft_print_char(str[j], i);
		j++;
	}
}
