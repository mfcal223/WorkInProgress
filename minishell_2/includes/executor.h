/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:03:52 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/18 15:35:44 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"
# include "environment.h"
# include "parser.h"

struct					s_cmd;
typedef struct s_cmd	t_cmd;

struct					s_redir;
typedef struct s_redir	t_redir;

typedef struct s_pipe
{
	int	(*pipefd)[2];
	int	pipe_count;
}	t_pipe;

//utils/utils_envpath.c 
void	free_split(char **split);
char	*find_full_path(char *cmd, char **path);
char	*get_command_path(char *cmd);
int		is_directory(const char *path);

//executor/exec_commands.c
char	*check_command_path(t_cmd *cmd, t_env *env);
void	child_process(char *cmd_path, t_cmd *cmd, char **envp, t_env *env);
pid_t	fork_and_execute(char *cmd_path, t_cmd *cmd, char **envp, t_env *env);
void	execute_external_command(t_cmd *cmd, t_env *env);
void	execute_command(t_cmd *cmd, t_env *env);

//utils/utils_executor.c
char	*ft_strjoin_3(char *s1, char *s2, char *s3);
char	**env_list_to_array(t_env *env);
void	handle_exit_status(int status, t_env *env);
int		handle_directory_or_meta_error(t_cmd *cmd, t_env *env);

//executor/exec_builtins.c
int		is_parent_builtin(char *cmd);
int		is_child_builtin(char *cmd);
void	execute_parent_builtin(char **args, t_env *env);
int		execute_child_builtin(char **args, t_env *env);
void	execute_builtin(char **args, t_env *env);

//executor/exec_pipes.c
int		count_pipes(t_cmd *cmd_list);
void	create_pipes(t_pipe *pipes);
void	close_pipes(t_pipe *pipes);
pid_t	fork_pipes(t_pipe *pipes, t_cmd *cmd_list, t_env *env, int i);
void	execute_pipeline(t_cmd *cmd_list, t_env *env);

//executor/exec_redirections.c
int		open_file(t_redir *redir, t_env *env);
int		execute_redirections(t_cmd *cmd, t_env *env);
int		handle_heredoc(const char *limiter);

//utils/utils_errors.c
void	handle_redirection_error(char *filename, t_env *env);
void	handle_exec_error(char *cmd_path, char **args);
void	handle_command_path_error(char *cmd_path, t_cmd *cmd, t_env *env);
void	handle_directory_error(t_cmd *cmd, t_env *env);

#endif
