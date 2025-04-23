/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:41:26 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/22 09:26:50 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exit_status.h"
#include "../../includes/executor.h"

/*
 * handle_redirection_error() = display error message for redirection failure.
 * Prints the filename followed by a system-generated error message.
 * Sets the exit status to indicate failure.
 */

void	handle_redirection_error(char *filename, t_env *env)
{
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	env->exit_status = EXIT_FAILURE;
}

/*
 * handle_exec_error() = handle errors after a failed execve() call.
 * Exits with the appropriate code based on errno:
 * - EACCES / EISDIR: not executable or is a directory.
 * - ENOENT / ENOEXEC: command not found or invalid format.
 * - Other errors: generic failure.
 * The cmd_path and args are ignored (placeholders).
 */

void	handle_exec_error(char *cmd_path, char **args)
{
	(void)cmd_path;
	(void)args;
	if (errno == EACCES || errno == EISDIR)
		exit (EXIT_NOT_EXECUTABLE);
	else if (errno == ENOENT)
		exit (EXIT_COMMAND_NOT_FOUND);
	else if (errno == ENOEXEC)
		exit(EXIT_COMMAND_NOT_FOUND);
	else
		exit (EXIT_FAILURE);
}

/*
 * handle_command_path_error() = handle error when a command path is invalid
 or not executable.
 * - If the file exists but is a directory: prints error and sets 
 "not executable" status.
 * - If the file exists but has no execute permission: prints permission denied.
 * - Otherwise, prints "command not found".
 * Sets the appropriate exit status in all cases.
 */

void	handle_command_path_error(char *cmd_path, t_cmd *cmd, t_env *env)
{
	if (cmd_path && access(cmd_path, F_OK) == 0)
	{
		if (is_directory(cmd_path))
		{
			ft_putstr_fd(cmd->args[0], 2);
			ft_putendl_fd(": Is a directory", 2);
			env->exit_status = EXIT_NOT_EXECUTABLE;
			return ;
		}
		else if (access(cmd_path, X_OK) != 0)
		{
			ft_putstr_fd(cmd->args[0], 2);
			ft_putendl_fd(": Permission denied", 2);
			env->exit_status = EXIT_NOT_EXECUTABLE;
			return ;
		}
	}
	ft_putstr_fd(cmd->args[0], 2);
	ft_putendl_fd(": command not found", 2);
	env->exit_status = EXIT_COMMAND_NOT_FOUND;
}

/*
 * handle_directory_error() = handle error when command points to a directory.
 * - If the command contains a '/', it's a path: prints "Is a directory".
 * - Otherwise, prints "command not found".
 * Sets the corresponding exit status.
 */

void	handle_directory_error(t_cmd *cmd, t_env *env)
{
	if (ft_strchr(cmd->args[0], '/'))
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": Is a directory", 2);
		env->exit_status = EXIT_NOT_EXECUTABLE;
	}
	else
	{
		ft_putstr_fd(cmd->args[0], 2);
		ft_putendl_fd(": command not found", 2);
		env->exit_status = EXIT_COMMAND_NOT_FOUND;
	}
}
