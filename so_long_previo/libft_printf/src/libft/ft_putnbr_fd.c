/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:59:02 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 12:59:21 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}
/*
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
*/
/*
int	main(void)
{
	int	nb;
	int	nb2;
	int	nb3;
	int	nb4;
	int	fd;

	nb = 256;
	nb2 = 2147483647;
	nb3 = -2147483648;
	nb4 = 0;
	fd = 1;
	ft_putnbr_fd(nb, fd);
	write (1, "\n", 1);
	ft_putnbr_fd(nb2, fd);
	write (1, "\n", 1);
	ft_putnbr_fd(nb3, fd);
	write (1, "\n", 1);
	ft_putnbr_fd(nb4, fd);
	write (1, "\n", 1);
	return (0);
}*/
