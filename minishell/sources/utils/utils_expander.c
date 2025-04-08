/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:44:55 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/08 08:40:39 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * get_variable_length() = get length of a variable name. 
 * Determines the length of an environment variable name in input.
 * * Skips processing if inside of single quotes.
 * * Returns 2 for special case '$?'.
 * * Otherwise, counts alphanumeric chars and '_'
 */

int	get_variable_length(const char *input, t_expand *exp)
{
	int		var_len;

	var_len = 1;
	if (exp && exp->single_quotes)
		return (var_len);
	if (input[1] == '?')
		return (2);
	while (input[var_len] && (ft_isalnum(input[var_len])
			|| input[var_len] == '_'))
		var_len++;
	return (var_len);
}

/*
 * get_variable_name() = extract the variable name. 
 * Allocates memory for and extracts the variable name from input. 
 * Uses get_variable_length to determine name length. 
 * Copies the variable name into a new allocated str. 
 */

char	*get_variable_name(const char *input, t_expand *exp)
{
	int		var_len;
	char	*var;

	var_len = get_variable_length(input, exp);
	var = malloc (var_len + 1);
	if (!var)
		return (NULL);
	ft_strlcpy(var, input, var_len + 1);
	return (var);
}

/*
 * get_variable_value() = retrieve variable value. 
 * Returns the value of an environment variable.
 * * If '$?', returns the exit status as a str.
 * * Otherwise, looks up the var in the environment. 
 * * Returns an empty str if variable is not found. 
 */

char	*get_variable_value(char *str, t_env *env)
{
	char	*result;
	char	*env_value;

	if (str[0] != '$')
		return (NULL);
	if (str[1] == '?')
		return (ft_itoa(env->exit_status));
	env_value = get_env_value(env, str + 1);
	if (env_value)
		result = ft_strdup(env_value);
	else
		result = ft_strdup("");
	return (result);
}
