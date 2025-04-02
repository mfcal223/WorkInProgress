/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:06:01 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/02 16:41:00 by mcalciat         ###   ########.fr       */
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
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
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
	if (!is_numeric(args[1]))
	{
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(args[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		env->exit_status = 255;
		quit_program(env);
	}
	if (args[2])
	{
		ft_putendl_fd("exit: too many arguments", STDERR_FILENO);
		env->exit_status = 1;
		return ;
	}
	code = ft_atoi(args[1]);
	env->exit_status = (unsigned char)code;
	quit_program(env);
}
