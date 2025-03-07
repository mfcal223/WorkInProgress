/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:42:11 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/07 16:56:14 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* duplicates the line and stores in a list node*/
t_map	*add_line(char *line)
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = ft_strdup(line);
	if (!new->map)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

/* appends new node to map list */
void	append_line(t_game *game, t_map *new)
{
	t_map	*last;

	last = game->map;
	if (!last)
		game->map = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	create_array(t_game *game, char *line)
{
	t_map	*new;

	if (line[0] == '\n')
	{
		ft_printf("Map error: found empty line.\n");
		free(line);
		close_handler(game, "Map creation failed.\n");
	}
	new = add_line(line);
	if (!new)
	{
		free(line);
		return ;
	}
	append_line(game, new);
	free(line);
}

int	check_extension(char *map)
{
	int	len;

	if (!map)
		return (1);
	len = ft_strlen(map);
	if (len < 5 || map[0] == '.')
		return (1);
	if (map[len - 4] == '.' && map[len - 3] == 'b' && map[len - 2] == 'e'
		&& map[len - 1] == 'r')
		return (0);
	return (1);
}
