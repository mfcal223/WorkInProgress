/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 10:03:42 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/02 14:32:49 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

/*
 * open_file() = opens a file based on the redirection type. 
 * If type is 0 (input redirection), opens the file for reading. 
 * If type is 1 (output redirection), opens the file for writing (truncates). 
 * If type is 2 (output append), opens the file for writing in append mode. 
 * If file opening fails, prints an error msg. 
 * Returns the file descriptor or -1 for failure. 
 */

int	open_file(t_redir redir)
{
	int	fd;

	if (redir.type == 0)
		fd = open(redir.file, O_RDONLY);
	else if (redir.type == 1)
		fd = open(redir.file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir.type == 2)
		fd = open(redir.file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (-1);
	if (fd == -1)
		perror("Redirection failed");
	return (fd);
}
/*
 * handle_redirections() = sets up file redirections for a command. 
 * Iterates through the command's redirections. 
 * Calls open_file() to get the file descriptor.
 * Redirects STDIN or STDOUT using dup2().
 * Closes the file descriptor after redirection.  
 */

int	handle_redirections(t_cmd *cmd)
{
	int	fd;
	int	i;

	if (!cmd->redir)
		return (0);
	i = 0;
	while (cmd->redir[i].file)
	{
		fd = open_file(cmd->redir[i]);
		if (fd == -1)
			return (-1);
		if (cmd->redir[i].type == 0)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close (fd);
		i++;
	}
	return (0);
}
/*
void	parse_redirection(t_cmd *cmd, char **args)
{
	int	i = 1;
	int	redir_index = 0;

	cmd->redir = malloc(sizeof(t_redir) * 3);
	while (args[i] && (args[i][0] == '<' || args[i][0] == '>' ))
	{
		if (args[i][0] == '<')
			cmd->redir[redir_index].type = 0;
		else if (args[i][0] == '>')
		{
			if (args[i][1] == '>')
				cmd->redir[redir_index].type = 2;
			else
				cmd->redir[redir_index].type = 1;
		}
		cmd->redir[redir_index].file = args[i + 1];
		i += 2;
		redir_index++;
	}
	cmd->redir[redir_index].file = NULL;
}

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