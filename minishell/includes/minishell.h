/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:46:30 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/24 17:33:46 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h> //readline, rl_on_new_line, rl_replace_line, 
				//rl_redisplay
# include <readline/history.h>	//rl_clear_history, add_history
# include <stdio.h> 		//printf
# include <stdlib.h> 		//malloc, free, getenv, exit
# include <unistd.h>		//write, access, read, close, getcwd, chdir, 
				//isatty, ttyname, ttyslot, dup, dup2, pipe
# include <fcntl.h>		//open
# include <sys/stat.h>		//stat, lstat, fstat
# include <dirent.h>		//opendir, readdir, closedir
# include <sys/types.h>		//general types (needed for fork, wait)
# include <sys/wait.h>		//wait, waitpid, wait3, wait4
# include <sys/resource.h>	//wait3, wait4
# include <signal.h>		//signal, sigaction, sigemptyset, sigaddset, kill
# include <errno.h>		//perror
# include <string.h>		//strerror
# include <sys/ioctl.h>		//ioctl
# include <termios.h>		//tcsetattr, tcgetattr
# include <curses.h>		//tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <term.h>		//additional terminal capabilities
# include "signal_handler.h"	//signal_handler
#endif
