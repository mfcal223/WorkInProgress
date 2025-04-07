/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:14:38 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/04 11:52:13 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "environment.h"
# include "executor.h"

typedef struct s_redir
{
	int		type;
	char	*file;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	int				input_fd;
	int				output_fd;
	int				pipe;
	t_redir			*redir;
	struct s_cmd	*next;	
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
t_cmd	*new_cmd(void);
char	**append_to_array(char **array, const char *new_str);
void	handle_new_cmd(t_cmd **cmd, t_cmd **head, t_cmd **current,
			t_cmd *new_cmd);
t_cmd	*parse_cmd(char **tokens, int *i);
t_cmd	*parse_tokens(char **tokens);

//parser/lexer.c
char	*handle_special_char(char **input);
char	*get_token(char **input);
char	**reallocate_tokens(char **tokens, int i, int *size);
char	**handle_token(char **tokens, char **input, int *i, int *size);
char	**lexer(char *input);

//utils/utils_cleaner.c
void	free_tokens(char **tokens);
void	free_cmd_list(t_cmd *cmd_list);

#endif
