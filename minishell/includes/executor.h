/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:03:52 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/04 11:24:31 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <sys/wait.h>
# include "../libft/libft.h"
# include "environment.h"	//environment structure

typedef struct s_pipe
{
    int (*pipefd)[2];
    int pipe_count;
}   t_pipe;


//utils/utils_envpath.c 
void	free_split(char **split);
char	*find_full_path(char *cmd, char **path);
char	*get_command_path(char *cmd);

//executor/exec_commands.c
char	*check_command_path(char *cmd);
pid_t	fork_and_execute(char *cmd_path, char **args, char **envp);
void	execute_external_command(char *cmd, char **args, t_env *env);
void	execute_command(char *cmd, char **args, t_env *env);

//utils/utils_executor.c
char	*ft_strjoin_3(char *s1, char *s2, char *s3);
char	**env_list_to_array(t_env *env);
void	handle_exit_status(int status, t_env *env);

//executor/exec_builtins.c
int		is_parent_builtin(char *cmd);
int		is_child_builtin(char *cmd);
void	execute_parent_builtin(char **args, t_env *env);
void	execute_child_builtin(char **args, t_env *env);
void	execute_builtin(char **args, t_env *env);

//executor/exec_pipes.c
int		count_pipes(char **cmds);
void	create_pipes(t_pipe *pipes);
void	close_pipes(t_pipe *pipes);
void	fork_pipes(t_pipe *pipes, char **args, t_env *env, int i);
void	execute_pipeline(char **cmds, t_env *env);

#endif
