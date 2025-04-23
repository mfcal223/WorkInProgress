/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:01 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 16:45:28 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/environment.h"

static int	is_numeric(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (*s == '\0')
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	handle_long_min(const char *str, int sign, long *out)
{
	if (sign == -1 && ft_strcmp(str, "9223372036854775808") == 0)
	{
		*out = LONG_MIN;
		return (1);
	}
	return (0);
}

int	ft_atol(const char *str, long *out)
{
	int		sign;
	long	result;
	long	prev;

	result = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (handle_long_min(str, sign, out))
		return (1);
	while (*str)
	{
		prev = result;
		result = result * 10 + (*str - '0');
		if (result < 0 || (result - (*str - '0')) / 10 != prev)
			return (0);
		str++;
	}
	*out = result * sign;
	return (1);
}

/**
 * You only want to print "exit\n" to the terminal when the user directly
 *     calls exit, not when it’s running inside a pipeline. 
 * So you pass is_forked = 0 in normal execution, and 1 inside a forked child.
 * 
 * env->exit_status is now your single source of truth for $?
 */
void	builtin_exit(char **args, t_env *env, int is_forked)
{
	long	code;

	if (!is_forked)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (!args[1])
		quit_program(env);
	if (!is_numeric(args[1]) || !ft_atol(args[1], &code))
	{
		ft_putendl_fd(" numeric argument required", 2);
		env->exit_status = EXIT_INVALID_USAGE;
		quit_program(env);
	}
	if (args[2])
	{
		ft_putendl_fd(" too many arguments", 2);
		env->exit_status = EXIT_FAILURE;
		return ;
	}
	env->exit_status = (unsigned char)code;
	quit_program(env);
}

/* WORKING VERSION - INCOMPLETE ERROR STATUS HADNLING
void	builtin_exit(char **args, t_env *env, int is_forked)
{
	long	code;

	if (!is_forked)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (!args[1])
		quit_program(env);
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		env->exit_status = EXIT_NON_NUMERIC;
		quit_program(env);
	}
	if (args[2])
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		env->exit_status = EXIT_FAILURE;
		return ;
	}
	code = ft_atoi(args[1]);
	env->exit_status = (unsigned char)code;
	quit_program(env);
}*/
