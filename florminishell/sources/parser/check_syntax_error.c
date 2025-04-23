/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:12:06 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 14:01:15 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/executor.h"

/**
 * is_redirection() checks if a token is a redirection 
 * 		operator:  *  " > ", " >> ", " < ", or " << ".
 */
int	is_redir(char *token)
{
	return (ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, ">>") == 0
		|| ft_strcmp(token, "<") == 0
		|| ft_strcmp(token, "<<") == 0);
}

/**
 * check_logic_sequence(): Validates logical operators || and &&
 * Ensures they are not followed by invalid tokens (|, redirections, or nothing).
 * If invalid, prints a Bash-like syntax error.
 */
int	check_logic_sequence(char **tokens, int i, t_env *env)
{
	if ((ft_strcmp(tokens[i], "||") == 0 || ft_strcmp(tokens[i], "&&") == 0)
		&& (!tokens[i + 1]
			|| ft_strcmp(tokens[i + 1], "|") == 0
			|| is_redir(tokens[i + 1])))
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		if (tokens[i + 1])
			ft_putstr_fd(tokens[i + 1], 2);
		else
			ft_putstr_fd("newline", 2);
		ft_putendl_fd("'", 2);
		env->exit_status = 2;
		return (1);
	}
	return (0);
}
/*
 * check_redir_pipe_sequence() = check for redirection or pipe
 followed by an invalid token (|, another redirection, or nothing).
 * If invalid, prints a syntax error.
 */

int	check_redir_pipe_sequence(char **tokens, int i, t_env *env)
{
	if (is_redir(tokens[i]) && (!tokens[i + 1] || is_redir(tokens[i + 1])
			|| ft_strcmp(tokens[i + 1], "|") == 0))
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		if (tokens[i + 1])
			ft_putstr_fd(tokens[i + 1], 2);
		else
			ft_putstr_fd("newline", 2);
		ft_putendl_fd("'", 2);
		env->exit_status = 2;
		return (1);
	}
	if (ft_strcmp(tokens[i], "|") == 0 && (!tokens[i + 1]
			|| ft_strcmp(tokens[i + 1], "|") == 0))
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		if (tokens[i + 1])
			ft_putstr_fd(tokens[i + 1], 2);
		else
			ft_putstr_fd("newline", 2);
		ft_putendl_fd("'", 2);
		env->exit_status = 2;
		return (1);
	}
	return (0);
}

/**
 * check_bad_operators() Detects malformed multi-character tokens
 * 		like: >>>, <<<, &&&&, ||||| 
 * If found, prints a syntax error near the unexpected token.
 */
int	check_bad_operators(char *token, t_env *env)
{
	if (!token)
		return (0);
	if (ft_strlen(token) > 2 && ft_strchr("|&<>", token[0]))
	{
		if (ft_strcmp(token, "<<<") == 0)
			return (0);
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(token, 2);
		ft_putendl_fd("'", 2);
		env->exit_status = 2;
		return (1);
	}
	return (0);
}

/**
 * detect_syntax_error() = Main validation function. 
 * Checks for operators as First-tokens (if (+) prints message).
 * Loops through all tokens to perform other checks
 */
int	detect_syntax_error(char **tokens, t_env *env)
{
	int	i;

	if (!tokens || !tokens[0])
		return (0);
	if (ft_strcmp(tokens[0], "|") == 0 || ft_strcmp(tokens[0], "||") == 0
		|| ft_strcmp(tokens[0], "&&") == 0)
	{
		ft_putendl_fd("syntax error near unexpected token `newline'", 2);
		env->exit_status = 2;
		return (1);
	}
	i = 0;
	while (tokens[i])
	{
		if (check_bad_operators(tokens[i], env))
			return (1);
		if (check_logic_sequence(tokens, i, env))
			return (1);
		if (check_redir_pipe_sequence(tokens, i, env))
			return (1);
		i++;
	}
	return (0);
}
