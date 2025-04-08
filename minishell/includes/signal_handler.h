/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:42:05 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/08 16:24:32 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <readline/readline.h> //readline, rl_on_new_line, rl_replace_line, 
# include <readline/history.h>	//rl_clear_history, add_history
# include <unistd.h>		//write, access, read, close, getcwd, chdir, 
# include <signal.h>		//signal, sigaction, sigemptyset, sigaddset, kill

# define IS_PARENT (g_is_parent == 1)
# define IS_CHILD  (g_is_parent == 0)

extern volatile sig_atomic_t g_is_parent;

void	catch_sigint(int signum);
void	setup_signals_interactive(void);
void	setup_signals_child(void);

#endif
