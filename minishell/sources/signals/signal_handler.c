/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:19:07 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/08 12:11:41 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/signal_handler.h"
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

volatile sig_atomic_t	g_is_parent = 1;

/** 
 * Resets signals to default for child processes
 * so they behave like in Bash (e.g., sleep, cat, etc.)
 * 
 * SIGINT (Ctrl+C) terminates the child
 * SIGQUIT prints Quit: 3 and terminates (like for cat) * 
 */
void	setup_signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	catch_sigint(int signum)
{
	if (g_is_parent)
	{
		(void)signum;
		write(1, "\n[SIGINT caught in parent]\n", 27);//DEBUG PRINT
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/*
** Sets up signal handlers for interactive shell mode
** - SIGINT (Ctrl+C) -> clears input and refreshes prompt
** - SIGQUIT (Ctrl+\) -> ignored
*/
void	setup_signals_interactive(void)
{
	struct sigaction	sa;

	sa.sa_handler = catch_sigint;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
    signal(SIGQUIT, SIG_IGN);
}
