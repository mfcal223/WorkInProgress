/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:47:50 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/04 11:08:05 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../../includes/environment.h"

/**
 * Checks if a string is a valid -n flag (e.g. "-n", "-nn", "-nnnn").
 * Used to determine if echo should suppress the trailing newline.
 *
 * @param str  The string to check.
 * @return     1 if the string is a valid -n flag, 0 otherwise.
 */
static int	is_valid_n_flag(char *str)
{
	int	i;

	if (!str || str[0] != '-' || str[1] != 'n')
		return (0);
	i = 2;
	while (str[i] == 'n')
		i++;
	return (str[i] == '\0');
}

/**
 * Mimics the behavior of the bash built-in echo command.
 * Supports multiple -n flags (e.g. -n, -nnn, -n -n) to suppress newline.
 *
 * @param ac   Argument count.
 * @param av   Argument values (e.g. {"echo", "-n", "hello", NULL}).
 */

int	builtin_echo(char **av, t_env *env)
{
	int		i;
	int		new_line;
	int		arg_count;

	i = 1;
	new_line = 1;
	arg_count = 0;
	while (av[arg_count])
		arg_count++;
	while (i < arg_count && is_valid_n_flag(av[i]))
	{
		new_line = 0;
		i++;
	}
	while (i < arg_count)
	{
		ft_putstr_fd(av[i], 1);
		if (i < arg_count - 1)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line)
		ft_putchar_fd('\n', 1);
	env->exit_status = 0;
	return (0);
}

/* ORIGINAL VERSION 
void	builtin_echo(int ac, char **av)
{
	int		i;
	int		new_line;

	i = 1;
	new_line = 1;
	while (i < ac && is_valid_n_flag(av[i]))
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
*/
