/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:30:58 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/23 10:03:17 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/executor.h"
#include "../../includes/environment.h"

/*
 * is_parent_builtin() = checks if the command is a parent-process built-in
 * Returns 1 if the command is cd, exit, export or unset. 
 * Otherwise, returns 0. 
 */

int	is_parent_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	else
		return (!ft_strncmp(cmd, "cd", ft_strlen("cd"))
			|| !ft_strncmp(cmd, "exit", ft_strlen("exit"))
			|| !ft_strncmp(cmd, "export", ft_strlen("export"))
			|| !ft_strncmp(cmd, "unset", ft_strlen("unset")));
}

/*
 * is_child_builtin() = checks if the command is a child-process built-in
 * Returns 1 if the command is echo, pwd or env.  
 * Otherwise, returns 0.
 */

int	is_child_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	else
		return (!ft_strncmp(cmd, "echo", ft_strlen("echo"))
			|| !ft_strncmp(cmd, "pwd", ft_strlen("pwd"))
			|| !ft_strncmp(cmd, "env", ft_strlen("env")));
}

/*
 * execute_parent_builtin() = Executes builtins that modify the shell state.
 * Calls the appropiate function for cd, exit, export, or unset.
 * (These commands do not create child processes).
 */

void	execute_parent_builtin(char **args, t_env *env)
{
	if (!ft_strncmp(args[0], "cd", ft_strlen(args[0])))
		builtin_cd(args, env);
	else if (!ft_strncmp(args[0], "exit", ft_strlen(args[0])))
		builtin_exit(args, env, 1);
	else if (!ft_strncmp(args[0], "export", ft_strlen(args[0])))
		builtin_export(args, env);
	else if (!ft_strncmp(args[0], "unset", ft_strlen(args[0])))
		builtin_unset(args, &env, &env->exit_status);
	return ;
}

/*
 * execute_child_builtin() = Executes builtins that run in a child process.
 * Forks a new process to execute echo, pwd or env. 
 * Calls the appropiate builtin functions and exits with its return value. 
 * Waits for the child process to complete.
 */
int	execute_child_builtin(char **args, t_env *env)
{
	if (!args || !args[0])
		return (EXIT_FAILURE);
	if (!ft_strncmp(args[0], "echo", ft_strlen("echo")))
		return (builtin_echo(args, env));
	if (!ft_strncmp(args[0], "pwd", ft_strlen("pwd")))
		return (builtin_pwd(env));
	if (!ft_strncmp(args[0], "env", ft_strlen("env")))
		return (builtin_env(env));
	if (!ft_strncmp(args[0], "exit", ft_strlen("exit")))
	{
		builtin_exit(args, env, 1);
		return (env->exit_status);
	}
	if (!ft_strncmp(args[0], "export", ft_strlen("export")))
	{
		builtin_export(args, env);
		return (env->exit_status);
	}
	if (!ft_strncmp(args[0], "unset", ft_strlen("unset")))
	{
		builtin_unset(args, &env, &env->exit_status);
		return (env->exit_status);
	}
	return (EXIT_FAILURE);
}

/*
 * execute_builtin() = determines and executes the appropiate builtin cmd.
 * Calls execute_parent_builtin() if the cmd modifies the shell state. 
 * Calls execute_child_builtin() if the cmd is standalone.
 * 
 * ⚠️ Important: You must not call this in the parent shell unless you're 
 * sure it won’t exit.
 */
void	execute_builtin(char **args, t_env *env)
{
	int	status;

	if (!args || !args[0])
		return ;
	if (is_parent_builtin(args[0]))
		execute_parent_builtin(args, env);
	else if (is_child_builtin(args[0]))
	{
		status = execute_child_builtin(args, env);
		if (IS_CHILD)
			exit(status);
		env->exit_status = status;
	}
}
