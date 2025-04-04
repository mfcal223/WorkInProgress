/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:03:31 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/03 11:08:41 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

/*
 * count_pipes() = count the number of pipes in the command sequence. 
 * Takes an array of command strings. 
 * Returns the number of pipes (one less than the number of commands). 
 */

int	count_pipes(char **cmds)
{
	int		count;

	count = 0;
	while (cmds[count])
		count++;
	return (count - 1);
}

/*
 * create_pipes() = create pipes for inter-process communication. 
 * Allocates pipes based on the number of commands. 
 * If pipe creation fails, prints an error and exits. 
 */

void	create_pipes(t_pipe *pipes)
{
	int	i;

	i = 0;
	while (i < pipes->pipe_count)
	{
		if (pipe(pipes->pipefd[i]) == -1)
		{
			perror("pipe failed");
			exit (1);
		}
		i++;
	}
}

/*
 * close_pipes() = close all pipes after use. 
 * Iterates through the pipe array and closes both read and write ends. 
 */

void	close_pipes(t_pipe *pipes)
{
	int		i;

	i = 0;
	while (i < pipes->pipe_count)
	{
		close(pipes->pipefd[i][0]);
		close(pipes->pipefd[i][1]);
		i++;
	}
}

/*
 * fork_pipes() = fork a child process and set up pie redirections. 
 * The first command writes the first pipe.
 * The last command reads from the last pipe. 
 * Intermediate commands read from the previos pipe and write to the next.
 * After stting up the pipes, executes the command. 
 */

void	fork_pipes(t_pipe *pipes, char **args, t_env *env, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit (1);
	}
	if (pid == 0)
	{
		if (i == 0 && pipes->pipe_count > 0)
			dup2(pipes->pipefd[0][1], STDOUT_FILENO);
		else if (i == pipes->pipe_count)
			dup2(pipes->pipefd[i - 1][0], STDIN_FILENO);
		else if (pipes->pipe_count > 0)
		{
			dup2(pipes->pipefd[i - 1][0], STDIN_FILENO);
			dup2(pipes->pipefd[i][1], STDOUT_FILENO);
		}
		close_pipes(pipes);
		execute_command(args[0], args, env);
		exit (0);
	}
}

/*
 * execute_pipeline() = execute a sequence of piped commands. 
 * Conuts pipes and creates the necessary pipe file descriptors. 
 * Forks processes for each command in the pipeline. 
 * After execution, closes pipes and waits for all child processes. 
 */

void	execute_pipeline(char **cmds, t_env *env)
{
	int		i;
	char	**args;
	t_pipe	pipes;

	pipes.pipe_count = count_pipes(cmds);
	if (pipes.pipe_count > 0)
	{
		pipes.pipefd = malloc(sizeof(*pipes.pipefd) * pipes.pipe_count);
		create_pipes(&pipes);
	}
	i = 0;
	while (cmds[i])
	{
		args = ft_split(cmds[i], ' '); //Replace with our parse_args function 
		fork_pipes(&pipes, args, env, i);
		free_split(args); // Replace with cleaning function.
		i++;
	}
	if (pipes.pipe_count > 0)
	{
		close_pipes(&pipes);
		free(pipes.pipefd);
	}
	while (i--)
		wait(NULL);
}

/*
//main to test
int	main(int argc, char **argv, char **envp)
{
	char	**cmds;
	
	if (argc != 2)
	{
		write(1, "Usage: ./executor \"cmd1 | cmd2 | cmd3\"\n", 36);
		return (1);
	}
	cmds = ft_split(argv[1], '|');
	execute_pipeline(cmds, envp);
	free_split(cmds);
	return (0);
}
*/