/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:11:59 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/23 12:04:38 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"
#include "../../includes/minishell.h"

/**
 * Join 3 substrings 
 * (strjoin in libft works woth 2 strings, not 3)
 */
char	*ft_strjoin_3(char *s1, char *s2, char *s3)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, s3);
	free(tmp);
	return (res);
}

/**
 * Helper: Convert t_env to char **envp 
 * for execute_external_comands()
 */
char	**env_list_to_array(t_env *env)
{
	t_env	*tmp;
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * (env_list_size(env) + 1));
	if (!arr)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		arr[i] = ft_strjoin_3(tmp->key, "=", tmp->value);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

/**
 * Updates the shell's last exit status after waitpid().
 */
void	handle_exit_status(int status, t_env *env)
{
	if (WIFEXITED(status))
		env->exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		env->exit_status = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(STDERR_FILENO, "Quit\n", 8);
	}
}

/*
** Handles special meta-command and directory cases before attempting execution.
**
** This function checks for:
** - "." → Prints "filename argument required", sets exit status 2
** - ".." → Treated as a command not found (matches Bash behavior),
sets exit status 127
** - "~" → Expands to $HOME and checks if it's a directory
** - Any other directory path → Prints "Is a directory" and sets exit status 126
**
** If a handled condition matches:
** - It prints the appropriate error message
** - Updates `env->exit_status`
** - Returns 1 to indicate that the command should not be executed
**
** If nothing matches, returns 0 to allow execution to proceed.
*/

int	handle_directory_or_meta_error(t_cmd *cmd, t_env *env)
{
	struct stat	buf;
	char		*home;

	if (ft_strcmp(cmd->args[0], ".") == 0)
	{
		ft_putendl_fd("minishell: .: filename argument required", 2);
		env->exit_status = 2;
		return (1);
	}
	if (ft_strcmp(cmd->args[0], "..") == 0)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(cmd->args[0], 2);
		env->exit_status = 127;
		return (1);
	}
	if (ft_strcmp(cmd->args[0], "~") == 0)
	{
		home = get_env_value(env, "HOME");
		if (home && stat(home, &buf) == 0 && S_ISDIR(buf.st_mode))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(home, 2);
			ft_putendl_fd(": Is a directory", 2);
			env->exit_status = 126;
			free(home);
			return (1);
		}
		free(home);
		return (0);
	}
	if (stat(cmd->args[0], &buf) == 0 && S_ISDIR(buf.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": Is a directory", 2);
		env->exit_status = 126;
		return (1);
	}
	return (0);
}
