/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:45:13 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/25 07:56:35 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	digit = (n % 10) + '0';
	write (fd, &digit, 1);
	return ;
}

/*int	main()
{
	int	num;

	num = -2147483648;
	ft_putnbr_fd(num, 1);
	write (1, "\n", 1);

	num = 42;
	ft_putnbr_fd(num, 1);
	write (1, "\n", 1);

	num = -42;
	ft_putnbr_fd(num, 1);
	write (1, "\n", 1);

	num = 0;
	ft_putnbr_fd(num, 1);
	write (1, "\n", 1);
}*/
