/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:39 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/07 14:17:08 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * init_expansion() = initialize expansion structure. 
 * Allocates memory for the expanded result string. 
 * Initializes expansion state variables: 
 * * Stores last exit status
 * * Tracks quote states (single and double)
 * * Sets result index to 0
 */

char	*init_expansion(t_expand *exp, char *input, int last_exit_status)
{
	exp->result = malloc (ft_strlen(input) + 1);
	if (!exp->result)
		return (NULL);
	exp->result_id = 0;
	exp->last_exit = last_exit_status;
	exp->single_quotes = 0;
	exp->double_quotes = 0;
	return (exp->result);
}

/*
 * handle_quotes() = set quote states. 
 * Tracks whether we are inside a single or double quotes. 
 * * Single quotes disable variable expansion. 
 * * Double quotes allow expansion but preserve spaces. 
 */
int	handle_quotes(char current, t_expand *exp)
{
	if (current == '\'' && !exp->double_quotes)
		exp->single_quotes = !exp->single_quotes;
	else if (current == '\"' && !exp->single_quotes)
		exp->double_quotes = !exp->double_quotes;
	return (0);
}

/*
 * replace_variable() = replace variable with its value. 
 * Skips expansion inside single quotes. 
 * Extracts variable name. 
 * Retrieves the variable value from environment or exit status. 
 * Inserts expanded value into result string. 
 */
char	*replace_variable(char *input, t_expand *exp, int *i)
{
	char	*var;
	char	*expander;
	int		var_len;
	int		j;

	if (exp->single_quotes)
	{
		exp->result[(exp->result_id)++] = input[(*i)++];
		return (exp->result);
	}
	var = get_variable_name(input + *i, exp);
	expander = get_variable_value(var, exp->last_exit);
	var_len = get_variable_length(input + *i, exp);
	free(var);
	if (expander)
	{
		j = 0;
		while (expander[j])
			exp->result[(exp->result_id)++] = expander[j++];
		free (expander);
		*i += var_len;
	}
	else
		exp->result[(exp->result_id)++] = input[(*i)++];
	return (exp->result);
}

/*
 * expand_variable() = expand all variables in input string. 
 * * Initializes expansion structure. 
 * * Iterates over the input string, handling: 
 * * * Quotes to track expansion rules. 
 * * * '$' symbol to expand environment variables. 
 * * * Copies normal characters to result. 
 */
char	*expand_variable(char	*input, int last_exit_status, int input_len)
{
	int			i;
	t_expand	exp;

	if (!init_expansion(&exp, input, last_exit_status))
		return (NULL);
	i = 0;
	while (i < input_len)
	{
		handle_quotes(input[i], &exp);
		if (input[i] == '$' && input[i + 1] && (ft_isalnum(input[i + 1])
				|| input[i + 1] == '_' || input[i + 1] == '?'))
		{
			if (!replace_variable(input, &exp, &i))
			{
				free(exp.result);
				return (NULL);
			}
		}
		else
			exp.result[(exp.result_id)++] = input[i++];
	}
	exp.result[exp.result_id] = '\0';
	return (exp.result);
}
/*
// main to test
int	main()
{
	int		i = 0;
	int		last_exit_status = 42;
	char	*expanded;
	char *inputs[] = {
        "$HOME",
        "$USER",
        "$?",
        "echo '$HOME'",
        "test$USER test",
        NULL
    };
    while (inputs[i])
    {
        int		input_len = ft_strlen(inputs[i]);
		printf("\nTest case %d:\n", i + 1);
        printf("Input: %s\n", inputs[i]);
        expanded = expand_string(inputs[i], last_exit_status, input_len);
        printf("Expanded: %s\n", expanded);
        free(expanded);
		i++;
    }
	return (0);
}
*/