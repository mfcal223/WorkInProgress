/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:02:52 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 09:38:51 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/environment.h"

/*
** Sorts a linked list of environment variables in-place
** using a basic bubble sort by comparing the key strings.
*/
void	sort_env_list(t_env *env)
{
	t_env	*next;
	char	*tmp_key;
	char	*tmp_value;

	while (env)
	{
		next = env->next;
		while (next)
		{
			if (ft_strcmp(env->key, next->key) > 0)
			{
				tmp_key = env->key;
				tmp_value = env->value;
				env->key = next->key;
				env->value = next->value;
				next->key = tmp_key;
				next->value = tmp_value;
			}
			next = next->next;
		}
		env = env->next;
	}
}

/*
** Creates a deep copy of the given environment variable list.
** This copy is used for sorting and printing without modifying the original.
*/
t_env	*copy_env_list(t_env *env)
{
	t_env	*copy;
	t_env	*tail;
	t_env	*new;

	copy = NULL;
	tail = NULL;
	while (env)
	{
		new = malloc(sizeof(t_env));
		if (!new)
			return (NULL);
		new->key = ft_strdup(env->key);
		if (env->value)
			new->value = ft_strdup(env->value);
		else
			new->value = NULL;
		new->next = NULL;
		if (!copy)
			copy = new;
		else
			tail->next = new;
		tail = new;
		env = env->next;
	}
	return (copy);
}

/**
 * Prints all environment variables in 'declare -x KEY="VALUE"' format.
 * Used when 'export' is called with no arguments.
 * The list is sorted alphabetically and freed after printing.
 */
int	print_export_list(t_env *env)
{
	t_env	*sorted;
	t_env	*tmp;

	sorted = copy_env_list(env);
	if (!sorted)
		return (1);
	sort_env_list(sorted);
	tmp = sorted;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp->key, 1);
		if (tmp->value)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('"', 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
	free_env_list(sorted);
	return (0);
}

/*int	print_export_list(t_env *env)
{
	while (env)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->key, 1);
		if (env->value)
		{
			ft_putchar_fd('=', 1);
			ft_putchar_fd('"', 1);
			ft_putstr_fd(env->value, 1);
			ft_putchar_fd('"', 1);
		}
		ft_putchar_fd('\n', 1);
		env = env->next;
	}
	return (0);
}*/