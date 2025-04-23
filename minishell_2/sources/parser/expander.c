/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:39 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/18 17:03:07 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/minishell.h"

/*
 * init_expansion() = initialize expansion structure. 
 * Allocates memory for the expanded result string. 
 * Initializes expansion state variables: 
 * * Stores last exit status
 * * Tracks quote states (single and double)
 * * Sets result index to 0
 */

char	*init_expansion(t_expand *exp)
{
	exp->result = malloc (1024);
	if (!exp->result)
		return (NULL);
	exp->result_id = 0;
	exp->single_quotes = 0;
	exp->double_quotes = 0;
	exp->expansion_active = 1;
	return (exp->result);
}

void	append_char(t_expand *exp, char c)
{
	exp->result[exp->result_id] = c;
	exp->result_id++;
}

/*
 * replace_variable() = replace variable with its value. 
 * Skips expansion inside single quotes. 
 * Extracts variable name. 
 * Retrieves the variable value from environment or exit status. 
 * Inserts expanded value into result string. 
 */
char	*replace_variable(char *input, t_expand *exp, int *i, t_env *env)
{
	char	*var;
	char	*expander;
	int		var_len;
	int		j;

	var = get_variable_name(input + *i + 1, exp);
	expander = get_variable_value(var, env);
	var_len = get_variable_length(input + *i + 1, exp);
	free(var);
	if (expander)
	{
		j = 0;
		while (expander[j])
			exp->result[(exp->result_id)++] = expander[j++];
		free (expander);
		*i += var_len + 1;
	}
	else
		append_char(exp, input[(*i)++]);
	return (exp->result);
}

/*
 * Don’t expand inside 'single quotes'
 */
void	handle_single_quote(t_expand *exp)
{
	exp->single_quotes = !exp->single_quotes;
	if (exp->single_quotes)
		exp->expansion_active = 0;
	else
		exp->expansion_active = 1;
}

/*
 * Expand inside "double quotes" but preserve literal characters
 */
void	handle_double_quote(t_expand *exp)
{
	exp->double_quotes = !exp->double_quotes;
	exp->expansion_active = 1;
}

/*
 * Returns true (non-zero) if c is one of Bash's special one-character
 shell variables.
 */
int	is_special_shell_var(char c)
{
	return (c == '@' || c == '*' || c == '#'
		|| c == '!' || c == '-' || ft_isdigit(c));
}

void	handle_expansion(char *input, t_expand *exp, int *i, t_env *env)
{
	if (input[*i + 1] && (ft_isalnum(input[*i + 1])
			|| input[*i + 1] == '_' || input[*i + 1] == '?'
			|| is_special_shell_var(input[*i + 1])))
	{
		replace_variable(input, exp, i, env);
	}
	else
	{
		append_char(exp, '$');
		(*i)++;
	}
}

/*
 * expand_variable() = expand all variables in input string. 
 * * Initializes expansion structure. 
 * * Iterates over the input string, handling: 
 * * * Quotes to track expansion rules. 
 * * * '$' symbol to expand environment variables. 
 * * * '~' to expand $HOME and mimic bash message //added 16/04
 * * * Copies normal characters to result. 
 */

char	*expand_variable(char *input, int input_len, t_env *env)
{
	t_expand	exp;
	int			i;
	char		c;

	i = 0;
	if (!init_expansion(&exp))
		return (NULL);
	while (i < input_len && input[i])
	{
		c = input[i];
		if (c == '\'' && exp.double_quotes == 0)
			handle_single_quote(&exp);
		else if (c == '\"' && exp.single_quotes == 0)
			handle_double_quote(&exp);
		else if (c == '$' && exp.expansion_active)
		{
			handle_expansion(input, &exp, &i, env);
			continue ;
		}
		else if (is_tilde_start(input, i) && exp.single_quotes == 0)
		{
			append_home(&exp, env);
			i++;
			continue ;
		}
		else
			append_char(&exp, c);
		i++;
	}
	exp.result[exp.result_id] = '\0';
	return (exp.result);
}

/**
 * backup - funciona ok 
 void	handle_expansion(char *input, t_expand *exp, int *i, t_env *env)
{
	if (input[*i + 1] && (ft_isalnum(input[*i + 1])
			|| input[*i + 1] == '_' || input[*i + 1] == '?'))
		replace_variable(input, exp, i, env);
	else
	{
		append_char(exp, '$');
		(*i)++;
	}
}
 */

/*
//VERSION #1 - ORIGINAL 1ST VERSION (SOFIA) - DOES NOT HANDLE QUOTES AT ALL
char	*expand_variable(char *input, int input_len, t_env *env)
{
	int			i;
	t_expand	exp;

	if (!init_expansion(&exp))
		return (NULL);
	i = 0;
	while (i < input_len)
	{
		handle_quotes(input[i], &exp);
		if ((input[i] == '$' && input[i + 1] && (ft_isalnum(input[i + 1])
				|| input[i + 1] == '_' || input[i + 1] == '?')))
		{
			if (!replace_variable(input, &exp, &i, env))
			{
				free(exp.result);
				return (NULL);
			}
		}
		else
		{
			if ((input[i] == '\"') || (input[i] == '\'' && !exp.double_quotes))
			{
				i++;
				continue ;
			}
			exp.result[(exp.result_id)++] = input[i++];
		}
	}
	exp.result[exp.result_id] = '\0';
	return (exp.result);
}
*/