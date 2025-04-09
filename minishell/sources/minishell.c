/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:44:00 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/09 16:14:17 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/parser.h"
#include "../includes/executor.h"

/*
 * expand_tokens() = expand environment variables in the token list. 
 * Iteartes through the tokens array. 
 * Expands variables within each token using expand_variable(). 
 * Frees the old token and replaces it with the expanded value. 
 */

void	expand_tokens(char **tokens, t_env *env)
{
	int		i;
	char	*expanded;

	i = 0;
	while (tokens[i])
	{
		expanded = expand_variable(tokens[i], ft_strlen(tokens[i]), env);
		if (!expanded)
		{
			free(tokens[i]);
			tokens[i] = NULL;
			return ;
		}
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
	int		redirection;

	if (cmd_list)
	{
		if (cmd_list->redir)
		{
			redirection = handle_redirections(cmd_list);
			if (redirection == -1)
			{
				perror("redirection failed");
				return ;
			}
		}
		if (cmd_list->pipe)
			execute_pipeline(cmd_list, env);
		else
			execute_command(cmd_list, env);
	}
	g_is_parent = 1; // restore signal handling context for next loop // debug ??????
}

/*
 * process_input() = process user input into commands.
 * Tokenizes input using lexer(). 
 * Expands variables in tokens. 
 * Parses tokens into a command list. 
 * Executes the parsed commands. 
 * Cleans up allocated memory.
 */

void	process_input(char *input, t_env *env)
{
	char	**tokens;
	t_cmd	*cmd_list;

	if (handle_special_cases(input, env))
		return ;
	tokens = lexer(input);
	if (!tokens)
	{
		perror("lexer failed");
		return ;
	}
	expand_tokens(tokens, env);
	cmd_list = parse_tokens(tokens, env);
	if (!cmd_list)
	{
		perror("parser failed");
		free_tokens(tokens);
		return ;
	}
	execute_commands(cmd_list, env);
	free_tokens(tokens);
	free_cmd_list(cmd_list);
}

/* MAIN VERSION THAT INCLUDES BASIC PARSING TO BE ABLE TO TEST BUILTIN FUNCTIONS */

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*env_list;
	char	*prompt;//borrar si se elimina el macro PROMPT

	(void)argc;
	(void)argv;
	(void)envp;
	setup_signals_interactive();
	g_is_parent = 1;
	env_list = init_env(envp);
	prompt = NULL;//borrar si se elimina el macro PROMPT
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt = PROMPT;
		input = readline(prompt);
		if (!input)
		{
			if (isatty(STDIN_FILENO))
				printf("exit\n");
			quit_program(env_list);
		}
		if (*input)
		{
			add_history(input);
			process_input(input, env_list);
		}
		free(input);
	}
}

/**
 * THIS SUGGESTED VERSION OF EXECUTE_COMMANDS() WOULD BE USEFUL IS OUR MINISHELL 
 * NEEDS TO HANDLE ";" - MULTIPLE/MIXED SEQUENCES .p.e. echo hello | grep h ; echo world ; ls -l | wc -l)
 * 
 void	execute_commands(t_cmd *cmd_list, t_env *env)
{
	while (cmd_list)
	{
		if (cmd_list->pipe)
		{
			execute_pipeline(cmd_list, env);
			while (cmd_list && cmd_list->pipe)
				cmd_list = cmd_list->next;
			if (cmd_list)
				cmd_list = cmd_list->next;
		}
		else
		{
			if (cmd_list->redir)
			{
				if (handle_redirections(cmd_list) == -1)
				{
					perror("redirection failed");
					return ;
				}
			}
			execute_command(cmd_list, env);
			cmd_list = cmd_list->next;
		}
	}
	g_is_parent = 1;
}

 */

/* VERSION DE MAIN QUE NO USA MACRO PARA EL PROMPT

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*env_list;

	(void)argc;
	(void)argv;
	(void)envp;
	setup_signals_interactive();
	g_is_parent = 1;
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
			process_input(input, env_list);
		}
		free(input);
	}
}

*/