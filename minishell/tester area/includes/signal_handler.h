/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:42:05 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/25 11:30:01 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <readline/readline.h> //readline, rl_on_new_line, rl_replace_line, 
# include <readline/history.h>	//rl_clear_history, add_history
# include <unistd.h>		//write, access, read, close, getcwd, chdir, 
# include <signal.h>		//signal, sigaction, sigemptyset, sigaddset, kill


void	catch_sigint(int signum);
void	setup_signals_interactive(void);
//void	setup_signals_child(void);

#endif