/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:14:38 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/22 15:59:15 by mpiantan         ###   ########.fr       */
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
	int		fd;
	char	*file;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	char			*path;
	int				pipe;
	char			*outfile;
	char			*infile;
	t_redir			**redir;
	struct s_cmd	*next;	
}	t_cmd;

typedef struct s_expand
{
	char	*result;
	int		result_id;
	int		last_exit;
	int		single_quotes;
	int		double_quotes;
	int		expansion_active;// = 0 ($var wont expand) / = 1 ($var will expand)
	t_env	*env; // if needed by replace_variable
}	t_expand;

//utils/utils_input.c
int		is_only_whitespace(const char *str);//handles >$ <only spaces or tabs>
int		is_comment_line(const char *str);	//handles >$ #
int		is_colon_builtin(const char *str);	// handles >$ :
int		is_exclamation(const char *str);	// handles >$ !
int		handle_special_cases(char *input, t_env *env);

//parser/check_syntax_error.c
int		is_redir(char *token);
int		check_logic_sequence(char **tokens, int i, t_env *env);
int		check_redir_pipe_sequence(char **tokens, int i, t_env *env);
int		check_bad_operators(char *token, t_env *env);
int		detect_syntax_error(char **tokens, t_env *env);

//utils/utils_expander.c
int		get_variable_length(const char *input, t_expand *exp);
char	*get_variable_name(const char *input, t_expand *exp);
char	*get_variable_value(char *str, t_env *env);

//parser/expander.c
char	*init_expansion(t_expand *exp);
void	handle_single_quote(t_expand *exp);
void	handle_double_quote(t_expand *exp);
void	append_char(t_expand *exp, char c);
char	*replace_variable(char *input, t_expand *exp, int *i, t_env *env);
void	handle_expansion(char *input, t_expand *exp, int *i, t_env *env);
char	*expand_variable(char	*input, int input_len, t_env *env);

//parser/expander2.c
int		is_tilde_start(char *input, int i);
void	append_home(t_expand *exp, t_env *env);

//utils/utils_parser.c
void	update_pipe_and_iterate(t_cmd *cmd, char **tokens, int *i);
int		expect_filename_or_token(char **tokens, int *i, t_env *env, t_cmd *cmd);

//parser/parser.c
t_cmd	*new_cmd(void);
char	**append_to_array(char **array, const char *new_str);
void	handle_new_cmd(t_cmd **cmd, t_cmd **head, t_cmd **current,
			t_cmd *new_cmd);
t_cmd	*parse_cmd(char **tokens, int *i);
t_cmd	*parse_tokens(char **tokens);

//parser/parser_redir.c
int		handle_redirection(t_cmd *cmd, char **tokens, int *i, int redir_type);
int		parse_input_redir(t_cmd *cmd, char **tokens, int *i);
int		parse_output_redir(t_cmd *cmd, char **tokens, int *i);
int		parse_redirection_token(t_cmd *cmd, char **tokens, int *i);

//utils/utils_redirections.c
t_redir	*create_redir(int type, char *file);
t_redir	**create_redir_array(t_redir *new_redir);
t_redir	**append_to_redir_array(t_redir **redir_array, t_redir *new_redir);

//parser/lexer.c
char	*handle_special_char(char **input);
char	*get_token(char **input);
char	**reallocate_tokens(char **tokens, int i, int *size);
char	**handle_token(char **tokens, char **input, int *i, int *size);
char	**lexer(char *input);

//utils/utils_cleaner.c
void	free_redir_array(t_redir **redir_array);
void	free_tokens(char **tokens);
void	free_cmd_list(t_cmd *cmd_list);

#endif
