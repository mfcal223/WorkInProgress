/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_envpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:47:58 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/02 14:38:10 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/executor.h"

/*
 * free_split() = frees an array of strings. 
 * Iterates through the array, freeing each str. 
 * Sets each freed pointer to NULL. 
 * Frees the array itself.
 */

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

/*
 * find_full_path() = finds the executable path of a command. 
 * Iterates through the PATH directories.
 * Concatenates each directory with the command name. 
 * Checks if the resulting path is executable. 
 * Returns the full path if found, or NULL if not found or error.
 */

char	*find_full_path(char *cmd, char **path)
{
	char	*temp;
	char	*full_path;
	int		i;

	if (!path || !cmd)
		return (NULL);
	i = 0;
	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		if (!temp)
			return (NULL);
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

/*
 * get_command_path() = resolves full path of an executable command. 
 * If the cmd is executable as given, returns its duplicate.
 * Otherwise, searches the directories in PATH for the cmd.
 * Returns the full path if found, or NULL not found or error. 
 */

char	*get_command_path(char *cmd)
{
	char	*path_env;
	char	**path;
	char	*full_path;

	if (!cmd || !cmd[0])
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path_env = getenv("PATH");
	if (!path_env || !*path_env)
	{	
		write(2, "minishell: PATH is not set\n", 27);
		return (NULL);
	}
	path = ft_split(path_env, ':');
	if (!path)
		return (NULL);
	full_path = find_full_path(cmd, path);
	free_split(path);
	return (full_path);
}
