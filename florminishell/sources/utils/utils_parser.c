/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:17:35 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 09:30:20 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

/*
 * update_pipe_and_itearate() = 
 * Auxiliary function to track pipes and iterate through tokens.
 */

void	update_pipe_and_iterate(t_cmd *cmd, char **tokens, int *i)
{
	if (tokens[*i] && ft_strncmp(tokens[*i], "|", 1) == 0)
	{
		cmd->pipe = 1;
		(*i)++;
	}
}

/*
 * expect_filename_or_token() = 
 * Detects missing token after redirection
 * Returns: 1 if OK, 0 if error (and sets exit)
 * shows error message
 */

int	expect_filename_or_token(char **tokens, int *i, t_env *env, t_cmd *cmd)
{
	if (!tokens[*i])
	{
		ft_putendl_fd("syntax error near unexpected token `newline'", 2);
		free_cmd_list(cmd);
		env->exit_status = 2;
		return (0);
	}
	return (1);
}
