/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:06:15 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 09:45:36 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdlib.h>

/**
 * @brief Compares two strings character by character.
 *
 * @param s1 First string.
 * @param s2 Second string.
 * @return Integer difference between first non-matching characters.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] || (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/**
 * @brief Retrieves the value of a variable from the env list.
 *
 * @param env Linked list of environment variables.
 * @param key Variable name to search for.
 * @return Pointer to value string if found, NULL otherwise.
 */
char	*get_env_value(t_env *env, const char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

/**
 * @brief Creates a new t_env node from a "key=value" string.
 *
 * @param env_entry String in the format "KEY=VALUE".
 * @return Newly allocated node, or NULL on failure.
 */
t_env	*create_env_node(char *env_entry)
{
	t_env	*node;
	char	*equal_sign;
	size_t	key_len;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	equal_sign = ft_strchr(env_entry, '=');
	if (!equal_sign)
		return (free(node), NULL);
	key_len = equal_sign - env_entry;
	node->key = ft_substr(env_entry, 0, key_len);
	if (!node->key)
		return (free(node), NULL);
	node->value = ft_strdup(equal_sign + 1);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	return (node);
}

/**
 * @brief Initializes a linked list of environment variables from envp.
 *
 * @param envp Array of strings like ["KEY=VALUE", ...].
 * @return Head of the created t_env list, or NULL on failure.
 */
t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	*current;
	int		i;
	t_env	*new_node;

	i = 0;
	head = NULL;
	while (envp[i])
	{
		new_node = create_env_node(envp[i]);
		if (!new_node)
		{
			free_env_list(head);
			return (NULL);
		}
		if (!head)
		{
			head = new_node;
			new_node->exit_status = 0;
		}
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	return (head);
}
