/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:37:23 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/31 16:46:06 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/environment.h"

/**
 * Splits an "arg" of the form "KEY=VALUE" into separate key and value pairs.
 * If no '=' is found, sets value to NULL.
 * 
 * @param arg   The argument to split.
 * @param key   Output: duplicated key.
 * @param value Output: duplicated value (or NULL if '=' not found).
 * 
 * (estara incluido en lo que esta haciendo Sofi??)
 */
void	split_key_value(char *arg, char **key, char **value)
{
	char	*equal_pos;

	equal_pos = ft_strchr(arg, '=');
	if (!equal_pos)
	{
		*key = ft_strdup(arg);
		*value = NULL;
	}
	else
	{
		*key = ft_substr(arg, 0, equal_pos - arg);
		*value = ft_strdup(equal_pos + 1);
	}
}
/**
 * Prints all environment variables in 'declare -x KEY="VALUE"' format.
 * Used when 'export' is called with no arguments.
 * 
 * @param env  The environment linked list.
 * @return     Always returns 0.
 */
int	print_export_list(t_env *env)
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
}

/**
 * Implements the 'export' built-in.
 * - With no arguments, prints the environment.
 * - With arguments, adds or updates variables in the env list.
 * 
 * @param args  Arguments to export (args[0] == "export").
 * @param env   The environment linked list.
 * @return      Always returns 0.
 */
int	builtin_export(char **args, t_env *env)
{
	int		i;
	char	*key;
	char	*value;

	if (!args[1]) // just 'export'
		return (print_export_list(env));

	i = 1;
	while (args[i])
	{
		split_key_value(args[i], &key, &value);
		if (is_valid_identifier(key))
		{
			set_env_value(env, key, value); // create or update
		}
		// if invalid: silently ignore (or add error later if needed)
		free(key);
		free(value);
		i++;
	}
	return (0);
}

