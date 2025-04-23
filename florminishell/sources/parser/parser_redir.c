/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:07:28 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 16:47:37 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
 * handle_redirection() = handles redirection (<, <<, >>, >) for a command.
 * Creates a redirection object with the given type and filename (next token).
 * Appends it to the command's redirection array.
 * Returns -1 if there's no filename or creation fails, 0 on success.
 */

int	handle_redirection(t_cmd *cmd, char **tokens, int *i, int redir_type)
{
	t_redir	*redir;
	int		heredoc_fd;

	if (!tokens[*i + 1])
		return (-1);
	if (is_directory(tokens[*i + 1]) == 1)
	{
		ft_putendl_fd("No such directory", 2);
		return (-1);
	}
	redir = create_redir(redir_type, tokens[++(*i)]);
	if (!redir)
		return (-1);
	if (redir_type == 3)
	{
		heredoc_fd = handle_heredoc(redir->file);
		if (heredoc_fd == -1)
			return (-1);
		redir->fd = heredoc_fd;
	}
	cmd->redir = append_to_redir_array(cmd->redir, redir);
	return (0);
}

/*
 * parse_input_redir() = parses input redirections (<< and <).
 * Calls handle_redirection() with the appropriate type (heredoc or input).
 * Skips the redirection and filename tokens after handling.
 * Returns 1 if a redirection was handled, -1 on error, or 0 if no match.
 */

int	parse_input_redir(t_cmd *cmd, char **tokens, int *i)
{
	if (ft_strcmp(tokens[*i], "<<") == 0)
	{
		if (handle_redirection(cmd, tokens, i, 3) == -1)
			return (-1);
		(*i)++;
		return (1);
	}
	if (ft_strcmp(tokens[*i], "<") == 0)
	{
		if (handle_redirection(cmd, tokens, i, 0) == -1)
			return (-1);
		(*i)++;
		return (1);
	}
	return (0);
}

/*
 * parse_input_redir() = parses output redirections (>> and >).
 * Calls handle_redirection() with the appropriate type (append or trunc).
 * Skips the redirection and filename tokens after handling.
 * Returns 1 if a redirection was handled, -1 on error, or 0 if no match.
 */

int	parse_output_redir(t_cmd *cmd, char **tokens, int *i)
{
	if (ft_strcmp(tokens[*i], ">>") == 0)
	{
		if (handle_redirection(cmd, tokens, i, 2) == -1)
			return (-1);
		(*i)++;
		return (1);
	}
	if (ft_strcmp(tokens[*i], ">") == 0)
	{
		if (handle_redirection(cmd, tokens, i, 1) == -1)
			return (-1);
		(*i)++;
		return (1);
	}
	return (0);
}

/*
 * parse_redirection_token() = parses the redirection token in the input.
 * Calls the appropiate parser to handle the specific type of redirection.
 * Returns 1 if a redirection was handled, -1 on error, or 0 if it's not a redir.
 */

int	parse_redirection_token(t_cmd *cmd, char **tokens, int *i)
{
	if (!tokens[*i])
		return (0);
	if (ft_strcmp(tokens[*i], ">>") == 0 || ft_strcmp(tokens[*i], ">") == 0)
		return (parse_output_redir(cmd, tokens, i));
	if (ft_strcmp(tokens[*i], "<<") == 0 || ft_strcmp(tokens[*i], "<") == 0)
		return (parse_input_redir(cmd, tokens, i));
	return (0);
}
