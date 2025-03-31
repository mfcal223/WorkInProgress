/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:44:00 by mpiantan          #+#    #+#             */
/*   Updated: 2025/03/31 16:49:09 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* MAIN VERSION THAT INCLUDES BASIC PARSING TO BE ABLE TO TEST BUILTIN FUNCTIONS */

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)envp;
	
	setup_signals_interactive();//calls signal_handlers (signal_handler.c / signal_handler.h)
		t_env	*env_list = init_env(envp);	// ✅ initialize env list
	while (1)
	{
		input = readline ("\001\033[1;32m\002minishell$ \001\033[0m\002");
		if (!input)
		{
			printf("exit\n");
			break ;
		}
		if (*input)
		{
			add_history(input);
			char **args = ft_split(input, ' '); // simple split for testing
			if (args && args[0])
			{
				if (is_parent_builtin(args[0]))
					execute_parent_builtin(args, env_list);
				else if (is_child_builtin(args[0]))
					execute_child_builtin(args, env_list);
				else
					printf("Command not recognized: %s\n", args[0]);
				free_split(args);
			}
		}
		//printf("Input received: %s\n", input);
		free(input);
	}
	free_env_list(env_list); // considerar closing_adm()
	return (0);
}

/**
 * 
void	closing_adm(t_env *env_list, char *input)
{
	free(input);
	free_env_list(env_list);
}
 */