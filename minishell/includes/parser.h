/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:14:38 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/01 16:38:13 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <string.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char	**args;
	int		input_fd;
	int		output_fd;
	int		pipe;
	struct s_cmd *next;	
}	t_cmd;

typedef struct s_expand
{
	char	*result;
	int		result_id;
	int		last_exit;
	int		single_quotes;
	int		double_quotes;
}	t_expand;

//utils/utils_expander.c
int		get_variable_length(const char *input, t_expand *exp);
char	*get_variable_name(const char *input, t_expand *exp);
char	*get_variable_value(char *str, int last_exit_status);

//parser/expander.c
char	*init_expansion(t_expand *exp, char *input, int last_exit_status);
int		handle_quotes(char current, t_expand *exp);
char	*replace_variable(char *input, t_expand *exp, int *i);
char	*expand_variable(char	*input, int last_exit_status, int input_len);

//parser/parser.c

#endif
