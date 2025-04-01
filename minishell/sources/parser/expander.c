/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:39:39 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/31 15:24:46 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*expand_variable(char *str, int last_exit_status)
{
	char	*result;
	char	*env_value;
	
	if (str[0] == '$')
	{
		if (str[1] == '?')
			return (ft_itoa(last_exit_status));
	}
	else
	{
		env_value = getenv(str + 1);
		if (env_value)
			result = ft_strdup(env_value);
		else
			result = ft_strdup(""); 
		return (result);
	}
	return (NULL);
}

char	*expand_string(char	*input, int last_exit_status)
{
	int	len;
	char	*result;
	int	result_id;
	int	i;
	char 	*expander;

	len =  ft_strlen(input);
	result = malloc (len * 2);
	if (!result)
		return (NULL);
	result_id = 0;
	i = 0;
	while (i < len)
	{
		if (input[i] == '$')
		{
			expander = expand_variable(&input[i], last_exit_status);
			if (expander)
			{
				int	j = 0;
				while (expander[j])
					result[result_id++] = expander[j++];
				free (expander);
			}
			i += 2;
		}
		else
			result[result_id++] = expander[i++];
	}
	result[result_id] = '\0';
	return (result);
}

int	main()
{
	int	last_exit_status = 42;
	char	*input = "echo $HOME $USER $?";
	char	*expanded;
	
	printf ("Input: %s\n", input);
	expanded = expand_string(input, last_exit_status);
	printf ("Expanded: %s\n", expanded);
	free(expanded);
	return (0);
}