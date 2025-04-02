/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:36:41 by mcalciat          #+#    #+#             */
/*   Updated: 2025/04/02 16:33:48 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/** Error printing auxiliary function:
 *  		- Error message printed to stderr (fd 2).
 *  		- Frees old_pwd to avoid leaks.
 * 			- Returns 1 to signal failure.
 */
static int	print_cd_error(char *path, char *old_pwd)
{
	if (!path)
		ft_putendl_fd("cd: HOME not set", 2);
	else
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	free(old_pwd);
	return (1);
}

int	builtin_cd(char **av, t_env *env)
{
	char	*path;
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (perror("getcwd"), 1);
	if (!av[1])
		path = get_env_value(env, "HOME");
	else
		path = av[1];
	if (!path || chdir(path) != 0)
		return (print_cd_error(path, old_pwd));
	new_pwd = getcwd(NULL, 0);
	if (!new_pwd)
		return (free(old_pwd), perror("getcwd"), 1);
	set_env_value(env, "OLDPWD", old_pwd);
	set_env_value(env, "PWD", new_pwd);
	free(old_pwd);
	free(new_pwd);
	env->exit_status = 0;
	return (0);
}
/**
 * Arguments: av = arguments from the shell, where av[0] is "cd" and av[1] 
 * (optional  * is the directory to change to. env: your linked list of 
 * environment variables.
 * 
 * Saves the current working directory before changing it.
 * getcwd(NULL, 0) allocates memory and returns the full path.
 * 
 * If no argument, fall back to $HOME. (ft_getenv(env, "HOME");)
 *  - If $HOME is not set, it becomes NULL — HOW ?????????????????????
 * 
 * CALLS chdir: changes the current directory.
 * 
 * 		If no valid path or chdir() fails: 
 * 			- call error printing auxiliary function
 * 		If success: 
 * 			- get new path and update env
 * 			- Updates environment variables accordingly.
 * 
 * Avoids memory leaks.
 */