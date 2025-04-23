/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <mpiantan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:23:28 by mpiantan          #+#    #+#             */
/*   Updated: 2025/04/22 09:36:04 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/*
 * create_redir() = Creates a new redirection object. 
 * Initializes each ibject with the specified type and file. 
 * Returns a pointer to the new redirection object.
 * If memory allocation fails, it returns NULL.
 */

t_redir	*create_redir(int type, char *file)
{
	t_redir	*redir;

	redir = (t_redir *) malloc (sizeof(t_redir));
	if (!redir)
	{
		perror ("failed to allocate memory for redirection");
		return (NULL);
	}
	redir->type = type;
	redir->file = file;
	return (redir);
}

/*
 * create_redir_array() = creates a new array for redir objects.
 * Returns the new_array for success, and NULL for failure. 
 */

t_redir	**create_redir_array(t_redir *new_redir)
{
	t_redir	**new_array;

	new_array = malloc (sizeof(t_redir *) * 2);
	if (!new_array)
		return (NULL);
	new_array[0] = new_redir;
	new_array[1] = NULL;
	return (new_array);
}

/*
 * append_to_redir_array() = Appends a new redir object to an existing array.
 * If the array is NULL, it creates a new array with the new redirection.
 * The array is resized as necessary to accommodate the new redirection. 
 * The old array is freed after the redirection is added.
 */

t_redir	**append_to_redir_array(t_redir **redir_array, t_redir *new_redir)
{
	int		i;
	int		j;
	t_redir	**new_array;

	i = 0;
	if (redir_array == NULL)
		return (create_redir_array(new_redir));
	while (redir_array[i])
		i++;
	new_array = malloc(sizeof(t_redir *) * (i + 2));
	if (!new_array)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_array[j] = redir_array[j];
		j++;
	}
	new_array[i] = new_redir;
	new_array[i + 1] = NULL;
	free(redir_array);
	return (new_array);
}
