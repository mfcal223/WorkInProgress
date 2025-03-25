/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:47:50 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/25 14:12:52 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] || (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/**
 * simulates "echo" 
 * if -n is detected, turns off \n flag. will not be printed
 */
void	builtin_echo(int ac, char **av)
{
	int		i;
	int		new_line;

	i = 1;
	new_line = 1;
	if (i < ac && ft_strcmp(av[i], "-n") == 0)
	{
		new_line = 0;
		i++;
	}
	while (i < ac)
	{
		ft_putstr_fd(av[i], 1);
		if (i < ac - 1)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line)
		ft_putchar_fd('\n', 1);
}

int	main(void)
{
	char *test1[] = {"echo", "hello", "world", NULL};
	char *test2[] = {"echo", "-n", "no", "newline", NULL};
	char *test3[] = {"echo", NULL};

	printf("Test 1:\n");
	builtin_echo(3, test1);

	printf("Test 2:\n");
	builtin_echo(1, test3);

	printf("Test 3:\n");
	builtin_echo(4, test2);

	return (0);
}
