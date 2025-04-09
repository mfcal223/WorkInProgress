/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:14:38 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/09 16:18:17 by mcalciat         ###   ########.fr       */
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
	char			*path;
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

//utils/utils_input.c
int		is_only_whitespace(const char *str);			//handles >$ <only spaces or tabs>
int		is_comment_line(const char *str);				//handles >$ #
int		is_colon_builtin(const char *str);				// handles >$ :
int		is_exclamation(const char *str);				// handles >$ !
int		handle_special_cases(char *input, t_env *env);	// calls all the others and returns to process_input()

//utils/utils_expander.c
int		get_variable_length(const char *input, t_expand *exp);
char	*get_variable_name(const char *input, t_expand *exp);
char	*get_variable_value(char *str, t_env *env);

//parser/expander.c
char	*init_expansion(t_expand *exp);
int		handle_quotes(char current, t_expand *exp);
char	*replace_variable(char *input, t_expand *exp, int *i, t_env *env);
char	*expand_variable(char	*input, int input_len, t_env *env);

//utils/utils_parser.c
void		update_pipe_and_iterate(t_cmd *cmd, char **tokens, int *i);

//parser/parser.c
t_cmd	*new_cmd(void);
char	**append_to_array(char **array, const char *new_str);
void	handle_new_cmd(t_cmd **cmd, t_cmd **head, t_cmd **current,
			t_cmd *new_cmd);
t_cmd	*parse_cmd(char **tokens, int *i, t_env *env);
t_cmd	*parse_tokens(char **tokens,t_env *env);
//t_cmd	*parse_cmd(char **tokens, int *i);
//t_cmd	*parse_tokens(char **tokens);

//parser/parser2.c
// + 3 static functions
int			parse_redirection_token(t_cmd *cmd, char **tokens, int *i, t_env *env);

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
