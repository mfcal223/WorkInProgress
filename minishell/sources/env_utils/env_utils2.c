/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:24:03 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/31 10:34:52 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include <stdlib.h>

/**
 * Checks if the key exists using get_env_value(env, key)
 * If not found → allocates a new node, sets key and value (via ft_strdup), 
 * and appends it to the end.
 * If found → uses set_env_value(env, key, value) to update
 */
void	update_env_var(t_env *env, const char *key, const char *value)
{
	if (!get_env_value(env, key))
	{
		t_env *new = malloc(sizeof(t_env));
		if (!new)
			return ;
		new->key = ft_strdup(key);
		new->value = ft_strdup(value);
		new->next = NULL;
		while (env && env->next)
			env = env->next;
		if (env)
			env->next = new;
	}
	else
		set_env_value(env, key, value);
}
