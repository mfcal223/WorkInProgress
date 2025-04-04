/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:00:11 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/02 12:01:14 by mpiantan         ###   ########.fr       */
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
	cmd->next = NULL;
	return (cmd);
}


/*
 * append_to_array() = append a string to an array.
 * Reallocates memory to expand the array by one element. 
 * Copies the new string to the last position.
 * Ensures the array remains NULL-terminated. 
 */
char	**append_to_array(char **array, const char *new_str)
{
	int	i;
	char	**new_array;

	i = 0;
	while (array && array[i])
		i++;
	new_array = malloc (sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (array && array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	new_array[i] = ft_strdup(new_str);
	new_array[i +1] = NULL;
	return (new_array);
}

/*
 * handle_new_cmd() = link the new command to the command list. 
 * If it is the first command, it initializes the list. 
 * If not, it appends the new command to the end of the list. 
 */

void	handle_new_cmd(t_cmd **cmd, t_cmd **head, t_cmd **current, t_cmd *new_cmd)
{
	if (!*cmd)
	{
		*cmd = new_cmd;
		*head = *cmd;
	}
	else
		(*current)->next = new_cmd;
	*current = new_cmd;
}
