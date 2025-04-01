/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:46:30 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/01 13:52:28 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h> //readline, rl_on_new_line, rl_replace_line, 
								//rl_redisplay
# include <readline/history.h>	//rl_clear_history, add_history
# include <stdio.h> 			//printf
# include <stdlib.h> 			//malloc, free, getenv, exit
# include <unistd.h>			//write, access, read, close, getcwd, chdir, 
								//isatty, ttyname, ttyslot, dup, dup2, pipe
# include <fcntl.h>				//open
# include <sys/stat.h>			//stat, lstat, fstat
# include <dirent.h>			//opendir, readdir, closedir
# include <sys/types.h>			//general types (needed for fork, wait)
# include <sys/wait.h>			//wait, waitpid, wait3, wait4
# include <sys/resource.h>		//wait3, wait4
# include <signal.h>			//signal, sigaction, sigemptyset, sigaddset, 
								//kill
# include <errno.h>				//perror
# include <string.h>			//strerror
# include <sys/ioctl.h>			//ioctl
# include <termios.h>			//tcsetattr, tcgetattr
# include <curses.h>			//tgetent, tgetflag, tgetnum, tgetstr, tgoto, 
								//tputs
# include <term.h>				//additional terminal capabilities
// Our libraries
# include "../libft/libft.h"
# include "executor.h"			//executor management
# include "signal_handler.h"	//signal_handler
# include "environment.h"		//environment structure

/*-----------BUILTINS---------------------------------*/
int		builtin_echo(char **av);					//changed arguments to match executor calls
int		builtin_pwd(void);							//pwd command
int		builtin_env(t_env *env);					//env command
int		builtin_cd(char **av, t_env *env);			//cd command
int		builtin_unset(char **args, t_env **env);	// unset command. Iterates thourgh arguments
void	unset_env_var(t_env **env, char *key);		//removes node from env list if match(+)
int		is_valid_identifier(char *str);				//Checks whether a given string is a valid shell variable identifier.

/*---- BUILTIN_EXPORT.C ---- */
void	print_export_error(char *arg);				// print error message when using wrong var syntax
char	*strip_quotes(char *str);					//removes "" in values if needed
void	split_key_value(char *arg, char **key, char **value);	//for export() - parses pairs key/value
int		print_export_list(t_env *env);				//for export() -prints ENV var list
int		builtin_export(char **args, t_env *env);	//main export() function

//builtins (***IN PROCESS***)
//int		builtin_exit(char **args);

//parser

//signals
void	catch_sigint(int signum);
void	setup_signals_interactive(void);

#endif
