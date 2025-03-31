/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:30:58 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/31 16:42:03 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/environment.h"
#include "../../includes/minishell.h"

/*
 * is_parent_builtin(cmd):
 * 
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
 * is_child_builtin(cmd):
 * 
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
 * execute_parent_builtin(args):
 * 
 */

void	execute_parent_builtin(char **args, t_env *env)
{
	if (!ft_strncmp(args[0], "cd", ft_strlen(args[0])))
		builtin_cd(args, env);
	/*//else if (!ft_strncmp(args[0], "exit", ft_strlen(args[0])))
		builtin_exit(args);*/
	else if (!ft_strncmp(args[0], "export", ft_strlen(args[0])))
		builtin_export(args, env);//updated arguments
	else if (!ft_strncmp(args[0], "unset", ft_strlen(args[0])))
		builtin_unset(args, &env);//updated arguments
	return ;
}

/*
 * execute_child_builtin(args, envp):
 * 
 */

void	execute_child_builtin(char **args, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		return ;
	}
	if (pid == 0)
	{
		if (!ft_strncmp(args[0], "echo", ft_strlen("echo")))
			exit (builtin_echo(args));
		if (!ft_strncmp(args[0], "pwd", ft_strlen("pwd")))
			exit (builtin_pwd());
		if (!ft_strncmp(args[0], "env", ft_strlen("env")))
			exit (builtin_env(env)); //Changed argument sent--> original = (envp)
		exit (1);
	}
	waitpid(pid, NULL, 0);
}

/*
 * execute_builtin(args, envp):
 * 
 */
//COMENTADO PARA TESTEAR BUILTIN FUNCTIONS
/*void	execute_builtin(char **args)
{
	if (!args || !args[0])
		return ;
	if (is_parent_builtin(args[0]))
		execute_parent_builtin(args);
	else if (is_child_builtin(args[0]))
		execute_child_builtin(args);
}*/
