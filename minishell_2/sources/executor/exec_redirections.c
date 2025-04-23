/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:03:42 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/23 10:19:42 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/minishell.h"

/*
 * handle_heredoc() = handles the heredoc redirection. 
 * Creates a pipe to store the input. 
 * Prompts the user for input using readline() and compares it with the limiter. 
 * If the input matches the limiter or if readline() returns NULL, it exits 
 the loop. 
 * Writes each line to the pipe, followed by a newline character. 
 * After the loop ends, closes the write end of the pipe and returns the read 
 end of the pipe.
 * If fails, prints an error message and returns -1.
 */

int	handle_heredoc(const char *limiter)
{
	int		pipe_fd[2];
	char	*line;

	if (pipe(pipe_fd) == -1)
		return (-1);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, limiter) == 0)
		{
			free (line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		write(pipe_fd[1], "\n", 1);
		free (line);
	}
	close (pipe_fd[1]);
	return (pipe_fd[0]);
}

/*
 * open_file() = opens a file based on the redirection type. 
 * If type is 0 (input redirection), opens the file for reading. 
 * If type is 1 (output redirection), opens the file for writing (truncates). 
 * If type is 2 (output append), opens the file for writing in append mode. 
 * if type is 3 (heredoc), calls handle_heredoc() function. 
 * If file opening fails, prints an error msg. 
 * Returns the file descriptor or -1 for failure. 
 */

int	open_file(t_redir *redir, t_env *env)
{
	int	fd;

	if (redir->type == 0)
		fd = open(redir->file, O_RDONLY);
	else if (redir->type == 1)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == 2)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	if (fd == -1)
		handle_redirection_error(redir->file, env);
	return (fd);
}
/*
 * execute_redirections() = sets up file redirections for a command. 
 * Iterates through the command's redirections. 
 * Calls open_file() to get the file descriptor.
 * Redirects STDIN or STDOUT using dup2().
 * Closes the file descriptor after redirection.  
 */

int	execute_redirections(t_cmd *cmd, t_env *env)
{
	int		fd;
	int		i;
	t_redir	*r;

	if (!cmd->redir)
		return (0);
	i = 0;
	while ((r = cmd->redir[i]))
	{
		if (r->type == 3)
			fd = r->fd;
		else
			fd = open_file(r, env);
		if (fd == -1)
			return (-1);
		if (r->type == 0 || r->type == 3)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close (fd);
		i++;
	}
	return (0);
}
/*
//main to test
int	main(int argc, char **argv, char **envp)
{
	char	**args;
	char	*cmd;
	
	if (argc != 2)
	{
		write(1, "Usage: ./executor \"cmd1 < input_file\"\n", 36);
		return (1);
	}
	t_redir redir[] = {
		{0, "input.txt"},
		{2, "output.txt"},
		{0, NULL}
	};
	t_cmd cmd_rd;
	cmd_rd.redir = redir;
	if (handle_redirections(&cmd_rd) == -1)
	{
		printf("Error handling redirection.\n");
		return (1);
	}
	args = ft_split(argv[1], ' ');
	cmd = args[0];
	execute_command(cmd, args, envp);
	free_split(args);
	return (0);
}
*/
