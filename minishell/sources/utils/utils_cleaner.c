/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:54:13 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/04 11:42:59 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * free_tokens() = cleaner function for tokens. 
 * Iterates through the tokens array. 
 * Frees each individual string and the array itself. 
 */

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/*
 * free_cmd_list() = cleaner function for cmd_list. 
 * Iterates through the cmd_list (linked list of t_cmd structures). 
 * Frees malloc for command arguments and then the t_cmd structures themselves. 
 */

void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*temp;
	int		i;

	while (cmd_list)
	{
		temp = cmd_list;
		if (cmd_list->args)
		{
			i = 0;
			while (cmd_list->args[i])
			{
				free(cmd_list->args[i]);
				i++;
			}
			free(cmd_list->args);
		}
		cmd_list = cmd_list->next;
		free(temp);
	}
}
