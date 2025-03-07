/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:34:02 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 11:37:44 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
//to test adding char in a .txt I have to create it and use open 
//and close functions
#include <unistd.h>
int	main()
{
	char	c;

	c = 'C';
	ft_putchar_fd(c, 1);
	return (0);
}*/
