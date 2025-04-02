/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expander.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:44:55 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/01 14:46:23 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"

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

char	*get_variable_value(char *str, int last_exit_status)
{
	char	*result;
	char	*env_value;

	if (str[0] != '$')
		return (NULL);
	if (str[1] == '?')
		return (ft_itoa(last_exit_status));
	env_value = getenv(str + 1);
	if (env_value)
		result = ft_strdup(env_value);
	else
		result = ft_strdup("");
	return (result);
}