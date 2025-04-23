/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:17:14 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/23 09:07:06 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/environment.h"
/**
 * Frees all nodes in a linked list of environment variables.
 *
 * @param env Pointer to the head of the environment list.
 */
void	free_env_list(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->value);
		free(env);
		env = tmp;
	}
}

/**
 * Frees all memory associated with a single t_env node
 */
void	free_env_node(t_env *node)
{
	if (!node)
		return ;
	/*if (node)
	{
		printf("DEBUG: freeing %s\n", node->key);
	}*/
	free(node->key);
	free(node->value);
	free(node);
}
