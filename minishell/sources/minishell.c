/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:44:00 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/02 17:19:44 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* MAIN VERSION THAT INCLUDES BASIC PARSING TO BE ABLE TO TEST BUILTIN FUNCTIONS */

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*env_list;
	char	**args;

	(void)argc;
	(void)argv;
	(void)envp;
	
	setup_signals_interactive();//calls signal_handlers (signal_handler.c / signal_handler.h)
	env_list = init_env(envp);	// ✅ initialize env list
	while (1)
	{
		input = readline ("\001\033[1;32m\002minishell$ \001\033[0m\002");
		if (!input)
		{
			printf("exit\n");
			quit_program(env_list);
		}
		if (*input)
		{
			add_history(input);
			args = ft_split(input, ' '); // simple split for testing
			if (args && args[0])
			{
				execute_command(args[0], args, env_list);//centralize the logic
				free_split(args);
			}
		}
		free(input);
	}
}

/**
 * 
void	closing_adm(t_env *env_list, char *input)
{
	free(input);
	free_env_list(env_list);
}
 */