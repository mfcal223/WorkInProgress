/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:44:00 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/07 14:48:15 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "../includes/parser.h"

/*
 * expand_tokens() = expand environment variables in the token list. 
 * Iteartes through the tokens array. 
 * Expands variables within each token using expand_variable(). 
 * Frees the old token and replaces it with the expanded value. 
 */

void	expand_tokens(char **tokens, int last_exit_status)
{
	int		i;
	char	*expanded;

	i = 0;
	while (tokens[i])
	{
		expanded = expand_variable(tokens[i], last_exit_status,
				ft_strlen(tokens[i]));
		free(tokens[i]);
		tokens[i] = expanded;
		i++;
	}
}

/*
 * execute_commands() = executes commands from a linked list. 
 * Iterates through the command list. 
 * Calls execute_pipeline() if the command has pipes. 
 * Calls execute_command() for standalone commands.
 */

void	execute_commands(t_cmd *cmd_list, t_env *env)
{
	while (cmd_list)
	{
		if (cmd_list->pipe)
			execute_pipeline(cmd_list, env);
		else
			execute_command(cmd_list->args[0], cmd_list->args, env);
		cmd_list = cmd_list->next;
	}
}

/*
 * process_input() = process user input into commands.
 * Tokenizes input using lexer(). 
 * Expands variables in tokens. 
 * Parses tokens into a command list. 
 * Executes the parsed commands. 
 * Cleans up allocated memory.
 */

void	process_input(char *input, int last_exit_status, t_env env)
{
	char	**tokens;
	t_cmd	*cmd_list;

	tokens = lexer(input);
	if (!tokens)
	{
		perror("lexer failed");
		return ;
	}
	expand_tokens(tokens, last_exit_status);
	cmd_list = parse_tokens(tokens);
	if (!cmd_list)
	{
		perror("parser failed");
		free_tokens(tokens);
		return ;
	}
	execute_commands(cmd_list, &env);
	free_tokens(tokens);
	free_cmd_list(cmd_list);
}

/* MAIN VERSION THAT INCLUDES BASIC PARSING TO BE ABLE TO TEST BUILTIN FUNCTIONS */

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*env_list;

	(void)argc;
	(void)argv;
	(void)envp;
	
	setup_signals_interactive();
	env_list = init_env(envp);
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
			process_input(input, env_list->exit_status, *env_list); //update last_exit_status
		}// cambiar 0 por env->exit_status???? si no ver como el expander captaria "?!"
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