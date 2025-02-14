/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:52:40 by mcalciat          #+#    #+#             */
/*   Updated: 2024/11/14 11:52:43 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> // write
# include <stdlib.h> // malloc and free
# include <stdarg.h> // va_list y macros
# include <stddef.h> // size_t y NULL
# include <limits.h> // test INT max y min
# include <stdio.h> // check with printf()

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"

int		ft_printf(const char *man_str, ...);
void	ft_print_char(char c, size_t *i);
void	ft_print_string(char *str, size_t *i);
void	ft_print_nbr(int num, size_t *i);
void	ft_print_uintnbr(unsigned int num, size_t *i);
void	ft_print_hexa(unsigned int nbr, char *base, size_t *i);
void	ft_print_ptr(void *ptr, size_t *i);
#endif
