/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:07:28 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/09 16:19:55 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

/**
 * Detects missing token after redirection
 * Returns: 1 if OK, 0 if error (and sets exit)
 * shows error message
 */
int	expect_filename_or_token(char **tokens, int *i, t_env *env, t_cmd *cmd)
{
	if (!tokens[*i])
	{
		ft_putendl_fd("minishell: syntax error near unexpected token `newline'", 2);
		free_cmd_list(cmd);
		env->exit_status = 2;
		return (0);
	}
	return (1);
}

static int	handle_append_redir(t_cmd *cmd, char **tokens, int *i, t_env *env)
{
	int	fd;

	(*i)++;
	if (!expect_filename_or_token(tokens, i, env, cmd))
		return (0);
	fd = open(tokens[*i], O_WRONLY | O_CREAT | O_APPEND, 0644);
	cmd->output_fd = fd;
	return (1);
}

static int	handle_trunc_redir(t_cmd *cmd, char **tokens, int *i, t_env *env)
{
	int	fd;

	(*i)++;
	if (!expect_filename_or_token(tokens, i, env, cmd))
		return (0);
	fd = open(tokens[*i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmd->output_fd = fd;
	return (1);
}

static int	handle_input_redir(t_cmd *cmd, char **tokens, int *i, t_env *env)
{
	int	fd;

	(*i)++;
	if (!expect_filename_or_token(tokens, i, env, cmd))
		return (0);
	fd = open(tokens[*i], O_RDONLY);
	cmd->input_fd = fd;
	return (1);
}

int	parse_redirection_token(t_cmd *cmd, char **tokens, int *i, t_env *env)
{
	if (ft_strncmp(tokens[*i], ">>", 2) == 0)
		return (handle_append_redir(cmd, tokens, i, env));
	else if (ft_strncmp(tokens[*i], ">", 1) == 0)
		return (handle_trunc_redir(cmd, tokens, i, env));
	else if (ft_strncmp(tokens[*i], "<", 1) == 0)
		return (handle_input_redir(cmd, tokens, i, env));
	return (2);
}

