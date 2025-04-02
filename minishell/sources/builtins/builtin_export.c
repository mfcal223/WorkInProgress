/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:37:23 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/02 16:34:42 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/environment.h"

void	print_export_error(char *arg)
{
	ft_putstr_fd("export: `", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd("': not a valid identifier", 2);
}

/**
 * removes "" if the value already has them 
 */
char	*strip_quotes(char *str)
{
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len >= 2 && str[0] == '"' && str[len - 1] == '"')
		return (ft_substr(str, 1, len - 2));
	return (ft_strdup(str));
}

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
		*value = strip_quotes(equal_pos + 1);
		dprintf(2, "[split] key: [%s] | value: [%s]\n", *key, *value); // DEBUG
	}
}

/**
 * Implements the 'export' built-in.
 * - With no arguments, prints the environment.(see builtin_export2.c)
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
	{
		env->exit_status = 0;//check if correct
		return (print_export_list(env));
	}
	i = 1;
	while (args[i])
	{
		dprintf(2, "RAW ARG[%d] = [%s]\n", i, args[i]);
		split_key_value(args[i], &key, &value);
		if (!is_valid_identifier(key))
			print_export_error(args[i]);
		else
			set_env_value(env, key, value);
		free(key);
		free(value);
		i++;
	}
	env->exit_status = 0;//check if correct here
	return (0);
}

