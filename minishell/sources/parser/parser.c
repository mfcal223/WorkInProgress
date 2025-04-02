/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:59 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/01 16:49:25 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * new_cmd() = Create command structure
 * Allocates memory for a t_cmd structure.
 * Initializes fields (args, fd, pipe).
 */

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd = malloc (sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->input_fd = STDIN_FILENO;
	cmd->output_fd = STDOUT_FILENO;
	cmd->pipe = 0;
	return (cmd);
}

/*
 * append_to_array() = append a string to an array.
 * Reallocates memory to expand the array by one element. 
 * Copies the new string to the last position.
 * Ensures the array remains NULL-terminated. 
 */

/*
 * parse_tokens() = Parse tokens
 * Iterates through tokenized input (lexer.c)
 * Detects pipes, input and output redirections. 
 * Stores command arguiments dynamically.  
 */

t_cmd	*parse_tokens(char **tokens)
{
	t_cmd	*cmd;
	int		i;

	cmd = new_cmd();
	i = 0;
	if (!cmd || !tokens)
		return (NULL);
	while (tokens[i])
	{
		if (ft_strncmp(tokens[i], "|", 1) == 0)
		{
			cmd->pipe = 1;
			break ;
		}
		else if (ft_strncmp(tokens[i], ">", 1) == 0)
			cmd->output_fd = open(tokens[++i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (ft_strncmp(tokens[i], ">>", 2) == 0)
			cmd->output_fd = open(tokens[++i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (ft_strncmp(tokens[i], "<", 1) == 0)
			cmd->input_fd = open(tokens[++i], O_RDONLY);
		else
			cmd->args = ft_calloc(cmd->args, tokens[i]);
		i++;
	}
	return (cmd);
}
/*
 * process_cmd() = Process command
 * Calls expander to expand variables.
 * Sends the processed command to executor for execution.
 */

void	process_cmd(t_cmd *cmd, int last_exit_status, char **envp)
{
	int	i;
	
	if (!cmd)
		return ;
	i = 0;
	while (cmd->args[i])
	{
		cmd->args[i] = expand_variable(cmd->args[i], last_exit_status, ft_strlen(cmd->args[i]));
		i++;
	}
	execute_command(cmd->args[0], cmd->args, envp);
}
