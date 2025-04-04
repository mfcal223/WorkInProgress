/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:09:16 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/03 14:27:38 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	*handle_special_char(char input)
{
	char	*token;

	token = malloc (2);
	if (!token)
		return (NULL);
	token[0] = input;
	token[1] = '\0';
	return (token);
}

char	*get_token(char **input)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	while (**input && **input != '>' && **input != '<' && **input != '|')
	{
		i++;
		(*input)++;
	}
	if (i == 0)
		return (NULL);
	token = malloc (i + 1);
	if (!token)
		return (NULL);
	j = 0;
	while (j < i)
	{
		token[j] = (*input)[j];
		j++;
	}
	token[i] = '\0';
	*input += i;
	return (token);
}

char	**reallocate_tokens(char **tokens, int i, int *size)
{
	char	**new_tokens;
	int		j;

	if (i >= *size - 1)
	{
		*size *= 2;
		new_tokens = malloc (sizeof(char *) * (*size));
		if (!new_tokens)
			return (NULL);
		j = 0;
		while (j < i)
		{
			new_tokens[j] = tokens[j];
			j++;
		}
		free(tokens);
		tokens = new_tokens;
	}
	return (tokens);
}

char	**handle_token(char **tokens, char **input, int *i, int *size)
{
	if (**input == ' ' || **input == '\n')
	{
		(*input)++;
		return (tokens);
	}
	if (**input == '>' || **input == '<' || **input == '|')
	{
		tokens[*i] = handle_special_char(**input);
		(*input)++;
		(*i)++;
		return (tokens);
	}
	tokens[*i] = get_token(input);
	(*i)++;
	if (*i >= *size - 1)
		tokens = reallocate_tokens(tokens, *i, size);
	return (tokens);
}

char	**lexer(char *input)
{
	char	**tokens;
	int		i;
	int		size;

	i = 0;
	size = 10;
	tokens = malloc (sizeof(char *) * size);
	if (!tokens)
		return (NULL);
	while (*input)
	{
		tokens = handle_token(tokens, &input, &i, &size);
		if (!tokens)
			return (NULL);
	}
	tokens[i] = NULL;
	return (tokens);
}
/*
//main to test
void print_tokens(char **tokens)
{
    int i = 0;
    while (tokens[i])
    {
        printf("Token[%d]: %s\n", i, tokens[i]);
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

int main()
{
    char input[] = "echo hello > file | cat < input.txt";
    char **tokens = lexer(input);

    if (!tokens)
    {
        printf("Lexer returned NULL.\n");
        return 1;
    }

    print_tokens(tokens);
    return 0;
}
*/