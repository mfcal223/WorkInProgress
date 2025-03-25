/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:44:00 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/24 17:32:22 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp;
	setup_signals_interactive();//calls signal_handlers (signal_handler.c / signal_handler.h)
	while (1)
	{
		input = readline ("\001\033[1;32m\002minishell$ \001\033[0m\002");
		//input = readline("minishell$ ");
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
}
