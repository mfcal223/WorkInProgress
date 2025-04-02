/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:49:54 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/02 17:05:39 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/minishell.h"

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

/**
 * handles exit status for execute_external_commands()
 */
static void	handle_exit_status(int status, t_env *env)
{
	if (WIFEXITED(status))
		env->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		env->exit_status = 128 + WTERMSIG(status);
}

/*
 * execute_external_command(cmd, args, envp):
 * Executes a command, either from an absolute path or by resolving the PATH.
 * If execution fails, prints an error message.
 */
void	execute_external_command(char *cmd, char **args, t_env *env)
{
	char	*cmd_path;
	char	**envp;
	pid_t	pid;
	int		status;

	cmd_path = check_command_path(cmd);
	if (!cmd_path)
		return ;
	envp = env_list_to_array(env);
	if (!envp)
	{
		perror("env conversion failed");
		if (cmd_path != cmd)
			free(cmd_path);
		env->exit_status = 1;
		return ;
	}
	pid = fork_and_execute(cmd_path, args, envp);
	waitpid(pid, &status, 0);
	handle_exit_status(status, env);
	if (cmd_path != cmd)
		free(cmd_path);
	free_split(envp);
}

/*
 * execute_commnad(cmd, args, envp):
 * 
 */
void	execute_command(char *cmd, char **args, t_env *env)
{
	if (!cmd || !args || !args[0])
		return ;
	if (is_parent_builtin(args[0]) || is_child_builtin(args[0]))
		execute_builtin(args, env);
	else
		execute_external_command(cmd, args, env);
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