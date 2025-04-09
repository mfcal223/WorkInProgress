/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:15:34 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/09 15:05:57 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"

int	is_only_whitespace(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

int	is_comment_line(const char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (*str == '#');
}

int	is_colon_builtin(const char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (*str == ':' && *(str + 1) == '\0');
}

int	is_exclamation(const char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (*str == '!' && *(str + 1) == '\0');
}

int	handle_special_cases(char *input, t_env *env)
{
	if (is_only_whitespace(input))
	{
		env->exit_status = 0;
		return (1);
	}
	if (is_colon_builtin(input))
	{
		env->exit_status = 0;
		return (1);
	}
	if (is_comment_line(input))
	{
		env->exit_status = 1;
		return (1);
	}
	if (is_exclamation(input))
	{
		env->exit_status = 1;
		return (1);
	}
	return (0);
}
