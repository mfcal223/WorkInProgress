/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:17:35 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/09 16:17:54 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

void	update_pipe_and_iterate(t_cmd *cmd, char **tokens, int *i)
{
	if (tokens[*i] && ft_strncmp(tokens[*i], "|", 1) == 0)
	{
		cmd->pipe = 1;
		(*i)++;
	}
}