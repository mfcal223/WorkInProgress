/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:03:52 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/31 11:16:37 by mcalciat         ###   ########.fr       */
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
void	execute_external_command(char *cmd, char **args, char **envp);
void	execute_command(char *cmd, char **args, char **envp);

//executor/exec_builtins.c
int		is_parent_builtin(char *cmd);
int		is_child_builtin(char *cmd);
void	execute_parent_builtin(char **args, t_env *env);
void	execute_child_builtin(char **args, t_env *env);
//void	execute_parent_builtin(char **args);//change the arguments for testing until parsing
//void	execute_child_builtin(char **args);//change the arguments for testing until parsing
//void	execute_builtin(char **args);

//executor/exec_pipes.c
int		count_pipes(char **cmds);
void	create_pipes(t_pipe *pipes);
void	close_pipes(t_pipe *pipes);
void	fork_pipes(t_pipe *pipes, char **args, char **envp, int i);
void	execute_pipeline(char **cmds, char **envp);

#endif
