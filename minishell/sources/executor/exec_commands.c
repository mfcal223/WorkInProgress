/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:49:54 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/26 14:37:42 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

/*
 * check_command_path(cmd, envp):
 * 
 */

char	*check_command_path(char *cmd)
{
	char	*cmd_path;

	cmd_path = cmd;
	if (cmd[0] != '/' && cmd[0] != '.')
	{
		cmd_path = get_command_path(cmd);
		if (!cmd_path)
		{
			write (2, "minishell: command not found: ", 30);
			ft_putendl_fd(cmd, 2);
			return (NULL);
		}
	}
	return (cmd_path);
}

/*
 * fork_and_execute(cmd_path, args, envp):
 * 
 */

pid_t	fork_and_execute(char *cmd_path, char **args, char **envp)
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
		if (execve(cmd_path, args, envp) == -1)
		{
			perror("execve failed");
			free(cmd_path);
			exit (127);
		}
	}
	return (pid);
}

/*
 * execute_external_command(cmd, args, envp):
 * Executes a command, either from an absolute path or by resolving the PATH.
 * If execution fails, prints an error message.
 */

void	execute_external_command(char *cmd, char **args, char **envp)
{
	pid_t	pid;
	int		status;
	int		exit_status;
	int		signal_number;
	char	*cmd_path;

	cmd_path = check_command_path(cmd);
	if (!cmd_path)
		return ;
	pid = fork_and_execute(cmd_path, args, envp);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		if (exit_status != 0)
			perror("command failed");
	}
	else if (WIFSIGNALED(status))
	{
		signal_number = WTERMSIG(status);
		perror("command was terminated");
	}
	if (cmd_path != cmd)
		free(cmd_path);
}

/*
 * execute_commnad(cmd, args, envp):
 * 
 */

void	execute_command(char *cmd, char **args, char **envp)
{
	if (!cmd || !args || !args[0])
		return ;
	if (is_parent_builtin(args[0]) || is_child_builtin(args[0]))
		execute_builtin(args);
	else
		execute_external_command(cmd, args, envp);
}

/*
 * main to test
int main(int argc, char **argv, char **envp)
{
    if (argc < 2)
    {
        printf("Usage: %s <command> [args]\n", argv[0]);
        return (1);
    }
    execute_command(argv[1], &argv[1], envp);
    return (0);
}
*/