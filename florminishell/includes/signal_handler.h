/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:42:05 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/22 10:01:05 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>

# define IS_PARENT (g_is_parent == 1)
# define IS_CHILD  (g_is_parent == 0)

extern volatile sig_atomic_t	g_is_parent;

void	catch_sigint(int signum);
void	setup_signals_interactive(void);
void	setup_signals_child(void);

#endif
