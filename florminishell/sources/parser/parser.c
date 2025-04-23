/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:59 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/22 16:33:26 by mpiantan         ###   ########.fr       */
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
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(t_cmd));
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
	int		i;
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
 * Parse_cmd() = parse a single command from tokens.
 * Iterates through tokens until it encounters a pipe. 
 * Handles input and output redirections. 
 * Stores arguments dynamically in the cmd structure. 
 */
t_cmd	*parse_cmd(char **tokens, int *i)
{
	t_cmd	*cmd;
	int		redir_handled;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	while (tokens[*i] && ft_strncmp(tokens[*i], "|", 1) != 0)
	{
		redir_handled = parse_redirection_token(cmd, tokens, i);
		if (redir_handled == -1)
			return (NULL);
		if (redir_handled == 1)
			continue ;
		if (!(cmd->args == NULL && tokens[*i][0] == '\0'))
			cmd->args = append_to_array(cmd->args, tokens[*i]);
		(*i)++;
	}
	return (cmd);
}

/*
 * handle_new_cmd() = link the new command to the command list. 
 * If it is the first command, it initializes the list. 
 * If not, it appends the new command to the end of the list. 
 */

void	handle_new_cmd(t_cmd **cmd, t_cmd **head, t_cmd **current,
		t_cmd *new_cmd)
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

/*
 * parse_tokens() = Parse tokens int a linked list of commands.
 * Iterates through tokenized input (lexer.c)
 * Calls parse_cmd() to create a command structure. 
 * Detects pipes and returns a linked list of commands.
 */

t_cmd	*parse_tokens(char **tokens)
{
	t_cmd	*new_cmd;
	t_cmd	*cmd;
	t_cmd	*head;
	t_cmd	*current;
	int		i;

	cmd = NULL;
	head = NULL;
	current = NULL;
	i = 0;
	if (!tokens)
		return (NULL);
	while (tokens[i])
	{
		new_cmd = parse_cmd(tokens, &i);
		if (!new_cmd)
		{
			free_cmd_list(head);
			return (NULL);
		}
		handle_new_cmd(&cmd, &head, &current, new_cmd);
		update_pipe_and_iterate(cmd, tokens, &i);
	}
	return (head);
}

/* // OLD VERSION - FROM PRE-FIXING ISSUES FROM EXCELL SHEET
// --------------------------------------------------
t_cmd	*parse_cmd(char **tokens, int *i)
{
	t_cmd	*cmd;

	cmd = new_cmd();
	if (!cmd)
		return (NULL);
	while (tokens[*i] && ft_strncmp(tokens[*i], "|", 1) != 0)
	{
		if (ft_strncmp(tokens[*i], ">", 1) == 0)
			cmd->output_fd = open(tokens[++(*i)], O_WRONLY | O_CREAT | O_TRUNC,
					0644);
		else if (ft_strncmp(tokens[*i], ">>", 2) == 0)
			cmd->output_fd = open(tokens[++(*i)], O_WRONLY | O_CREAT | O_APPEND,
					0644);
		else if (ft_strncmp(tokens[*i], "<", 1) == 0)
			cmd->input_fd = open(tokens[++(*i)], O_RDONLY);
		else
			cmd->args = append_to_array(cmd->args, tokens[*i]);
		(*i)++;
	}
	return (cmd);
}

t_cmd	*parse_tokens(char **tokens)
{
	t_cmd	*new_cmd;
	t_cmd	*cmd;
	t_cmd	*head;
	t_cmd	*current;
	int		i;

	cmd = NULL;
	head = NULL;
	current = NULL;
	i = 0;
	if (!tokens)
		return (NULL);
	while (tokens[i])
	{
		new_cmd = parse_cmd(tokens, &i);
		if (!new_cmd)//Add null check before calling handle_new_cmd() 
		{
			free_cmd_list(head);  // if you have this helper
			return (NULL);        // stop early to avoid undefined behavior
		}
		handle_new_cmd(&cmd, &head, &current, new_cmd);
		if (tokens[i] && ft_strncmp(tokens[i], "|", 1) == 0)
		{
			cmd->pipe = 1;
			i++;
		}
	}
	return (head);
}
*/