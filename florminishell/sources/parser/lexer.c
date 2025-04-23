/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:09:16 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/22 11:20:49 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * handle_special_char() = Creates a token for a special character. 
 * Allocates memory for a 3-char string (1 or 2 chars + null terminator). 
 * Stores the input character(s) and returns the token. 
 * Returns NULL if malloc fails. 
 */

char	*handle_special_char(char **input)
{
	char	*token;

	token = malloc (3);
	if (!token)
		return (NULL);
	token[0] = **input;
	token[1] = '\0';
	(*input)++;
	if ((token[0] == '>' && **input == '>') || (token[0] == '<'
			&& **input == '<') || (token[0] == '|' && **input == '|')
		|| (token[0] == '&' && **input == '&'))
	{
		token[1] = **input;
		token[2] = '\0';
		(*input)++;
	}
	return (token);
}

/*
 * get_token() = Extracts a word token from the input string. 
 * **input is a pointer to the current position in the input string.
 * Skips leading spaces. 
 * Identifies a token by scanning until a space or a spaceial char. 
 * Allocates memory and copies the token into a new string. 
 * Returns the token or NULL if no valid token is found. 
 */
char	*get_token(char **input)
{
	char	*token;
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (**input == ' ' || **input == '\n')
		(*input)++;
	while ((*input)[i])
	{
		if ((quote == 0) && ((*input)[i] == '\'' || (*input)[i] == '"'))
			quote = (*input)[i];
		else if (quote && (*input)[i] == quote)
			quote = 0;
		else if (((*input)[i] == ' ' || (*input)[i] == '>' ||
				(*input)[i] == '<' || (*input)[i] == '|') && quote == 0)
			break ;
		i++;
	}
	if (i == 0)
		return (NULL);
	token = malloc(i + 1);
	if (!token)
		return (NULL);
	ft_strlcpy(token, *input, i + 1);
	*input += i;
	return (token);
}

/*
 * reallocate_tokens() = expands the token array if needed. 
 * Doubles the array size when full. 
 * Allocates new memory and copies existing tokens. 
 * Frees the old array and returns the new one. 
 * Returns NULL if malloc fails. 
 */

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

/*
 * handle_token() = processes the new token in the input string. 
 * Skips whitespaces and newlines. 
 * Handles special chars (>, <, |) as individual tokens. 
 * Extracts word tokens using get_token(). 
 * (actually walks through the characters of the word token "" or '' inc)
 * Expands the token array if necessary. 
 * Returns the updated token array. 
 */

char	**handle_token(char **tokens, char **input, int *i, int *size)
{
	while (**input == ' ' || **input == '\n')
		(*input)++;
	if (**input == '>' || **input == '<' || **input == '|' || **input == '&')
	{
		tokens[*i] = handle_special_char(input);
		(*i)++;
	}
	else
	{
		tokens[*i] = get_token(input);
		if (tokens[*i])
			(*i)++;
	}
	if (*i >= *size - 1)
		tokens = reallocate_tokens(tokens, *i, size);
	return (tokens);
}

/*
 * lexer() = tokenizes an input string. 
 * Initializes a dynamic array for tokens. 
 * Iterates trough the input, extracting tokens. 
 * Returns an array of token strings, terminated by NULL. 
 * Returns NULL if malloc fails. 
 */

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
char	*get_token(char **input)
{
	char	*token;
	int		i;

	i = 0;
	while (**input == ' ')
		(*input)++;
	while ((*input)[i] && (*input)[i] != ' ' && (*input)[i] != '>' &&
		(*input)[i] != '<' && (*input)[i] != '|')
		i++;
	if (i == 0)
		return (NULL);
	token = malloc (i + 1);
	if (!token)
		return (NULL);
	ft_strlcpy(token, *input, i + 1);
	token[i] = '\0';
	*input += i;
	return (token);
}
*/