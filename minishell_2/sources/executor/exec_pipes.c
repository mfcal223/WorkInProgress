/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:03:31 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/23 12:04:28 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/parser.h"
#include "../../includes/minishell.h"

/*
 * count_pipes() = count the number of pipes in the command sequence. 
 * Takes an array of command strings. 
 * Returns the number of pipes (one less than the number of commands). 
 */

int	count_pipes(t_cmd *cmd_list)
{
	int		count;

	count = 0;
	while (cmd_list)
	{
		count++;
		cmd_list = cmd_list->next;
	}
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
	pipes->pipefd = malloc (sizeof (int [2]) * pipes->pipe_count);
	if (!pipes->pipefd)
	{
		perror ("failed malloc for pipes");
		exit (1);
	}
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

pid_t	fork_pipes(t_pipe *pipes, t_cmd *cmd_list, t_env *env, int i)
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
		g_is_parent = 0;
		if (i == 0 && pipes->pipe_count > 0)
			dup2(pipes->pipefd[i][1], STDOUT_FILENO);
		else if (i == pipes->pipe_count)
			dup2(pipes->pipefd[i - 1][0], STDIN_FILENO);
		else if (pipes->pipe_count > 0)
		{
			dup2(pipes->pipefd[i - 1][0], STDIN_FILENO);
			dup2(pipes->pipefd[i][1], STDOUT_FILENO);
		}
		close_pipes(pipes);
		if (cmd_list->redir)
		{
			if (execute_redirections(cmd_list, env) == -1)
				exit (1);
		}
		execute_command(cmd_list, env);
	}
	return (pid);
}

/*
 * execute_pipeline() = execute a sequence of piped commands. 
 * Conuts pipes and creates the necessary pipe file descriptors. 
 * Forks processes for each command in the pipeline. 
 * After execution, closes pipes and waits for all child processes. 
 */

void	execute_pipeline(t_cmd *cmd_list, t_env *env)
{
	int		i;
	int		status;
	t_pipe	pipes;
	pid_t	pid;
	pid_t	last_pid;
		
	last_pid = -1;
	pipes.pipe_count = count_pipes(cmd_list);
	if (pipes.pipe_count > 0)
		create_pipes(&pipes);
	i = 0;
	g_is_parent = 0; //added to fix double prompt issue
	while (cmd_list)
	{
		if (!cmd_list->args || !cmd_list->args[0])
		{
			cmd_list = cmd_list->next;
			continue ;
		}
		last_pid = fork_pipes(&pipes, cmd_list, env, i);
		cmd_list = cmd_list->next;
		i++;
	}
	if (pipes.pipe_count > 0)
	{
		close_pipes(&pipes);
		free(pipes.pipefd);
	}
	while (i--)
	{
		pid = wait(&status);
		if (pid == last_pid)
			handle_exit_status(status, env);
	}
	g_is_parent = 1; //added to fix double prompt issue
}
