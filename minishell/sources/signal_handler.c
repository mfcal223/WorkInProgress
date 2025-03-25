/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:19:07 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/25 11:44:59 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/signal_handler.h"
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void	catch_sigint(int signum)
{
	(void)signum;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
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

/* //main for testing 
int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp;
    setup_signals_interactive();//ADD THIS IN REAL MAIN
	while (1)
	{
		input = readline ("\001\033[1;32m\002minishell$ \001\033[0m\002");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
			add_history(input);
		printf("Input received: %s\n", input);
		free(input);
	}
	return (0);
}*/

/* TO CHANGE SIGQUIT HANDLER IF NEEDED (IT DIDNOT WORK OK)
// in setup_signals_interactive()
	sa.sa_handler = catch_sigquit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa, NULL);

void	catch_sigquit(int signum)
{
	(void)signum;
	// future code for handling SIGQUIT
}*/

/*--------- TO USE WHEN CHILD PROCESSES ----------------*/
/*
** Resets signals to default for child processes
** so they behave like in Bash (e.g., sleep, cat, etc.)
*/
/*void	setup_signals_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}*/

/*// Usage in fork() before executing child
pid = fork();
if (pid == 0)
{
	setup_signals_child();
	// execve() or command execution
}
else
{
	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(1, "Quit: 3\n", 8);
	}
}

*/
