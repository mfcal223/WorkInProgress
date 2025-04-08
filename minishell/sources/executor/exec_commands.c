/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:49:54 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/08 15:06:03 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/minishell.h"

/*
 * check_command_path() = resolve command path
 * If the command starts with '/' or '.', it is an absolute/relative path. 
 * If not, it searches for the command in the system's PATH. 
 * If the command is not found, it prints an error and returns NULL. 
 */

char	*check_command_path(t_cmd *cmd)
{
	char	*cmd_path;

	cmd_path = cmd->path;
	if (cmd->path == NULL || (cmd->path[0] != '/' && cmd->path[0] != '.'))
	{
		cmd_path = get_command_path(cmd->args[0]);
		if (!cmd_path)
		{
			write (2, "minishell: command not found: ", 30);
			ft_putendl_fd(cmd->args[0], 2);
			return (NULL);
		}
	}
	return (cmd_path);
}

/*
 * fork_and_execute() = fork a child process and execute command. 
 * Creates a child process using fork(). 
 * The child process executes the command using execve(). 
 * If fork fails, it prints an error and exits. 
 * If execve fails, the child prints an error and exits with status 127. 
 */

pid_t	fork_and_execute(char *cmd_path, t_cmd *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free(cmd_path);
		exit (1);
	}
	if (pid == 0)
	{
		printf("[DEBUG] Executing cmd: %s\n", cmd->args ? cmd->args[0] : "NULL"); //DEBUG PRINT
		g_is_parent = 0;//global variable - signals behaviour for child processes
		printf("[FORK] In child (pid = %d)\n", getpid());//DEBUG PRINT
		printf("[FORK] In parent, waiting\n");//DEBUG PRINT
		setup_signals_child(); // not sure this is the right place
		if (cmd->redir)
		{
			if (handle_redirections(cmd) == -1)
			{
				perror("redirection failed");
				exit(1);
			}
		}
		if (execve(cmd_path, cmd->args, envp) == -1)
		{
			perror("execve failed");
			free(cmd_path);
			if (errno == EACCES)
				exit(126); // ✅ Not executable
			exit (127);// don’t need to call exit(127) here / shouldn't happen if check_command_path worked
		}
	}
	return (pid);
}

/*
 * execute_external_command() = run an external command. 
 * Resolves the command path. 
 * Forks a child process to execute the command. 
 * Waits for the process to finish and retrieves the exit status. 
 * Prints an error msg if the command fails o is terminated. 
 * Frees the resolved command path if it was dynamically allocated. 
 */
void	execute_external_command(t_cmd *cmd, t_env *env)
{
	char	*cmd_path;
	char	**envp;
	pid_t	pid;
	int		status;

	cmd_path = check_command_path(cmd);
	if (!cmd_path)
	{
		env->exit_status = EXIT_COMMAND_NOT_FOUND; // ✅ Bash-compatible "command not found"
		return ;
	}
	envp = env_list_to_array(env);
	if (!envp)
	{
		perror("env conversion failed");
		if (cmd_path != cmd->path)
			free(cmd_path);
		env->exit_status = 1;
		return ;
	}
	pid = fork_and_execute(cmd_path, cmd, envp);
	waitpid(pid, &status, 0);
	handle_exit_status(status, env);
	if (cmd_path != cmd->path)
		free(cmd_path);
	free_split(envp);
}

/*
 * execute_command() = execute a built-in or external command. 
 * If no command or arguments are provided, return. 
 * If the command is a built-in, calls the builtin executer. 
 * Otherwise, calls the executor for external command.  
 */
void	execute_command(t_cmd *cmd, t_env *env)
{
	if (!cmd || !cmd->args || !cmd->args[0])
		return ;
	if (is_parent_builtin(cmd->args[0]) || is_child_builtin(cmd->args[0]))
		execute_builtin(cmd->args, env);
	else
		execute_external_command(cmd, env);
}
