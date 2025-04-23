/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:59:50 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/23 09:06:54 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/environment.h"

/**
 * Searches for a variable with the given key in the t_env linked list and 
 * 		removes it if found.
 * If the key is not present, does nothing.
 * curr is the current node you're looking at. 
 * prev tracks the previous node, which is needed to re-link the list 
 * 		if curr gets deleted.
 * Uses free_env_node() to safely free the removed node.
 */
void	unset_env_var(t_env **env, char *key)
{
	t_env	*curr;
	t_env	*prev;

	if (!env || !*env)
		return ;
	curr = *env;
	prev = NULL;
	while (curr)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			//printf("DEBUG: removing key %s\n", key);//DEBUG PRINT
			if (prev)
				prev->next = curr->next;
			else
			{
				*env = curr->next;
				if (*env)
					(*env)->exit_status = curr->exit_status;
			}
			free_env_node(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

/**
 * Iterates over the provided arguments and
 *      removes valid environment variables from the list.
 * t_env **env is passed as a double pointer so you can 
 * 		modify the head of the list if needed.
 * Silently skip invalid identifiers (no printed message).
 * returns 0 (success)
 */
int	builtin_unset(char **args, t_env **env, int *exit_status)
{
	int		i;
	int		error;

	i = 1;
	error = 0;
	while (args[i])
	{
		//printf("DEBUG: checking identifier: %s\n", args[i]);//DEBUG PRINT
		if (!is_valid_identifier(args[i]))
		{
			//fprintf(stderr, "DEBUG: INVALID IDENTIFIER: %s\n", args[i]);//DEBUG PRINT
			ft_putstr_fd("unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			error = EXIT_FAILURE;
		}
		else
		{
			//printf("is_valid: %d\n", is_valid_identifier("SHELL"));//DEBUG PRINT
			unset_env_var(env, args[i]);
		}
		i++;
	}
	//printf("DEBUG final error = %d\n", error);
	*exit_status = error;
	//printf("DEBUG: exit status = %d\n", *exit_status);//DEBUG PRINT
	return (0);
}

/* VERSION QUE FUNCIONA PERO INCOMPLET ERROR EXIT HANDLING
int	builtin_unset(char **args, t_env **env)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (is_valid_identifier(args[i]))
			unset_env_var(env, args[i]);
		i++;
	}
	(*env)->exit_status = 0;
	return (0);
}*/