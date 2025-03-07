/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uintnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:46:10 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/19 10:46:20 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uintnbr(unsigned int num, size_t *i)
{
	if (num > 9)
	{
		ft_print_nbr(num / 10, i);
		ft_print_nbr(num % 10, i);
	}
	else
		ft_print_char(num + '0', i);
}
