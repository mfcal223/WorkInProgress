/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:12:38 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/13 11:12:41 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_specif(va_list var, const char *fs, size_t *i)
{
	if (*fs == 'c')
		ft_print_char(va_arg(var, int), i);
	else if (*fs == 's')
		ft_print_string(va_arg(var, char *), i);
	else if (*fs == 'p')
		ft_print_ptr(va_arg(var, void *), i);
	else if (*fs == 'i' || *fs == 'd')
		ft_print_nbr(va_arg(var, int), i);
	else if (*fs == 'u')
		ft_print_uintnbr(va_arg(var, unsigned int), i);
	else if (*fs == 'x')
		ft_print_hexa(va_arg(var, unsigned int), HEXA_LOWER, i);
	else if (*fs == 'X')
		ft_print_hexa(va_arg(var, unsigned int), HEXA_UPPER, i);
	else if (*fs == '%')
		ft_print_char('%', i);
}

int	ft_printf(const char *man_str, ...)
{
	va_list	var;
	size_t	i;
	size_t	j;

	if (*man_str == '\0')
		return (0);
	va_start(var, man_str);
	i = 0;
	j = 0;
	while (man_str[j])
	{
		if (man_str[j] == '%')
		{
			j++;
			ft_format_specif(var, &man_str[j], &i);
		}
		else
		{
			ft_print_char(man_str[j], &i);
		}
		j++;
	}
	va_end(var);
	return (i);
}
