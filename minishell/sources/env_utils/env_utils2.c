/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:24:03 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/01 10:21:05 by mcalciat         ###   ########.fr       */
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
			return;
		}
		last = env;
		env = env->next;
	}
	add_env_variable(last, key, value);
}

