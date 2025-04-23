/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:44:55 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/23 10:20:20 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * get_variable_length() = get length of a variable name. 
 * Determines the length of an environment variable name in input.
 * * //ya no es valido---> Skips processing if inside of single quotes.
 * * Returns 1 for special case '$?'.
 * * Otherwise, counts alphanumeric chars and '_'
 */
int	get_variable_length(const char *input, t_expand *exp)
{
	int	len;

	(void)exp;
	if (!input || *input == '\0')
		return (0);
	if (ft_isdigit(input[0]) || input[0] == '@' || input[0] == '*'
		|| input[0] == '#' || input[0] == '-' || input[0] == '!'
		|| input[0] == '?')
		return (1);
	len = 0;
	while (input[len])
	{
		if (!ft_isalnum(input[len]) && input[len] != '_')
			break ;
		len++;
	}
	return (len);
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

	if (!str || !*str)
		return (NULL);
	if (str[0] == '?')
		return (ft_itoa(env->exit_status));
	if (ft_strcmp(str, "UID") == 0)
		return (ft_itoa(getuid())); // special variable
	//if add to handle $0-9 $@ $* $# $! and $- 
	if (ft_isdigit(str[0]) || str[0] == '@' || str[0] == '*' ||
		str[0] == '#' || str[0] == '-' || str[0] == '!')
		return (ft_strdup("")); // empty string in interactive shell
	env_value = get_env_value(env, str);
	if (env_value)
		result = ft_strdup(env_value);
	else
		result = ft_strdup("");
	return (result);
}
