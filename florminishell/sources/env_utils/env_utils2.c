/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:24:03 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 09:44:29 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

/**
 * Appends a new t_env node if the key is not found
 */
void	add_env_variable(t_env *last, const char *key, const char *value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return ;
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	else
		new->value = NULL;
	new->next = NULL;
	last->next = new;
}

/**
 * @brief Sets or updates the value of an existing env variable.
 * Updates if the key is found
 * Call add_env_variable() if it needs to be created.
 * @param env Linked list of environment variables.
 * @param key Variable name to update.
 * @param value New value string (will be duplicated).
 */
void	set_env_value(t_env *env, const char *key, const char *value)
{
	t_env	*last;

	last = env;
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			free(env->value);
			if (value)
				env->value = ft_strdup(value);
			else
				env->value = NULL;
			return ;
		}
		last = env;
		env = env->next;
	}
	add_env_variable(last, key, value);
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

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
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
 * counts how many nodes the list has
 */
int	env_list_size(t_env *env)
{
	int	count;

	count = 0;
	while (env)
	{
		count++;
		env = env->next;
	}
	return (count);
}
