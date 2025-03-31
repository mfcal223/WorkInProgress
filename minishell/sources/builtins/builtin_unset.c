/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:59:50 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/31 16:38:14 by mcalciat         ###   ########.fr       */
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
			if (prev)
				prev->next = curr->next;
			else
				*env = curr->next;
			free_env_node(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
/**
 * Checks whether a given string is a valid shell variable identifier.
 * A valid identifier must start with a letter, and contain only letters, 
 *      digits, or underscores.
 * returns (1) if the identifier is valid, (0) otherwise.
 * Also use by builtin_export() DO NOT MAKE THIS STATIC
 */
int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !ft_isalpha(str[0]))
		return (0);
	i = 1;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
/**
 * Iterates over the provided arguments and
 *      removes valid environment variables from the list.
 * t_env **env is passed as a double pointer so you can 
 * 		modify the head of the list if needed.
 * Silently skip invalid identifiers (no printed message).
 * returns 0 (success)
 */
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
	return (0);
}

