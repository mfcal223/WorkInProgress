/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:49:54 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/18 15:55:06 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/minishell.h"

/*
 * check_command_path() = resolve the full executable path of a command.
 * If the command is an absolute or relative path (starts with '/' or '.'),
 use it as-is.
 * Otherwise, search for the command in the system's PATH.
 * If the path is invalid, not executable, or points to a directory,
 * handle the error and return NULL. 
 */

char	*check_command_path(t_cmd *cmd, t_env *env)
{
	char	*cmd_path;

	cmd_path = cmd->path;
	if (!cmd_path || (cmd_path[0] != '/' && cmd_path[0] != '.'))
		cmd_path = get_command_path(cmd->args[0]);
	if (!cmd_path || access(cmd_path, F_OK) != 0 || access(cmd_path, X_OK) != 0)
	{
		handle_command_path_error(cmd_path, cmd, env);
		if (cmd_path != cmd->path)
			free(cmd_path);
		return (NULL);
	}
	if (is_directory(cmd_path))
	{
		handle_directory_error(cmd, env);
		if (cmd_path != cmd->path)
			free(cmd_path);
		return (NULL);
	}
	return (cmd_path);
}

/*
 * child_process() = execute command logic in the child process after fork.
 * Sets up signal handling for child.
 * Executes redirections if any.
 * If the command is a built-in, execute it and exit with its status.
 * If there's a directory/meta error, handle it and exit with the error status.
 * Otherwise, attempt to execve() the command.
 * If execve fails, print error and exit.
 */

void	child_process(char *cmd_path, t_cmd *cmd, char **envp, t_env *env)
{
	int	status;

	g_is_parent = 0;
	setup_signals_child();
	if (cmd->redir)
	{
		if (execute_redirections(cmd, env) == -1)
			exit(1);
	}
	if (is_child_builtin(cmd->args[0]))
	{
		status = execute_child_builtin(cmd->args, env);
		exit (status);
	}
	if (handle_directory_or_meta_error(cmd, env))
	{
		free(cmd_path);
		exit(env->exit_status);
	}
	if (execve(cmd_path, cmd->args, envp) == -1)
	{
		free(cmd_path);
		handle_exec_error(cmd_path, cmd->args);
	}
}

/*
 * fork_and_execute() = fork a child process and execute a command.
 * On failure to fork, prints an error and exits.
 * In the child process, calls child_process().
 * In the parent process, waits for the child to finish,
 retrieves and sets the exit status, and frees resources. 
 */

pid_t	fork_and_execute(char *cmd_path, t_cmd *cmd, char **envp, t_env *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		free(cmd_path);
		exit (1);
	}
	if (pid == 0)
		child_process(cmd_path, cmd, envp, env);
	else
	{
		waitpid(pid, &status, 0);
		handle_exit_status(status, env);
		if (cmd_path != cmd->path)
			free(cmd_path);
		free_split(envp);
	}
	return (pid);
}

/*
 * execute_external_command() = run an external (non-built-in) command.
 * Resolves the command path using check_command_path().
 * Converts environment list to array format.
 * Forks and executes the command using fork_and_execute().
 * Handles memory cleanup and sets exit status on failure. 
 */
void	execute_external_command(t_cmd *cmd, t_env *env)
{
	char	*cmd_path;
	char	**envp;
	pid_t	pid;

	if (!cmd->path && (cmd->args[0][0] == '/' || cmd->args[0][0] == '.'))
		cmd->path = ft_strdup(cmd->args[0]);
	cmd_path = check_command_path(cmd, env);
	if (!cmd_path)
		return ;
	envp = env_list_to_array(env);
	if (!envp)
	{
		if (cmd_path != cmd->path)
			free(cmd_path);
		env->exit_status = EXIT_FAILURE;
		return ;
	}
	pid = fork_and_execute(cmd_path, cmd, envp, env);
}

/*
 * execute_command() = dispatch the execution of a command.
 * If no command is provided, returns immediately.
 * In a child process: executes built-in or external cmd, then exits.
 * In the parent process: executes built-in or external cmd without exiting.
 */

void	execute_command(t_cmd *cmd, t_env *env)
{
	int	status;

	if (!cmd || !cmd->args || !cmd->args[0] || cmd->args[0][0] == '\0')
		return ;
	if (IS_CHILD)
	{
		if (is_parent_builtin(cmd->args[0]) || is_child_builtin(cmd->args[0]))
		{
			status = execute_child_builtin(cmd->args, env);
			exit (status);
		}
		else
		{
			execute_external_command(cmd, env);
			exit (env->exit_status);
		}
	}
	else
	{
		if (is_parent_builtin(cmd->args[0]))
			execute_builtin(cmd->args, env);
		else
			execute_external_command(cmd, env);
	}
}
