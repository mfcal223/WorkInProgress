/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:36:20 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 15:22:59 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(t_game *game)
{
	t_map	*tmp;
	char	**duplicate;
	int		i;

	i = 0;
	tmp = game->map;
	duplicate = malloc(sizeof(char *) * (game->size.y + 1));
	if (!duplicate)
		return (NULL);
	while (game->map)
	{
		duplicate[i] = ft_strdup(game->map->map);
		if (!duplicate[i])
		{
			free_duplicate(duplicate, i);
			return (NULL);
		}
		i++;
		game->map = game->map->next;
	}
	game->map = tmp;
	duplicate[i] = NULL;
	return (duplicate);
}

int	map_x_width(t_map *width, t_game *game)
{
	int	x;

	x = 0;
	while (width->map[x] && width->map[x] != '\n')
		x++;
	if (x > 27)
	{
		close_handler(game, "Map is too wide.\n");
		return (-1);
	}
	return (x);
}

int	map_y_heigth(t_map *height, t_game *game)
{
	int	y;

	y = 0;
	while (height)
	{
		y++;
		height = height->next;
	}
	if (y > 18)
	{
		close_handler(game, "Map has too many rows.\n");
		return (-1);
	}
	return (y);
}

t_map	*create_map(t_game *game)
{
	char	*line;
	int		fd;

	fd = open(game->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Map file is corrupt or does not exist.\n");
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		create_array(game, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (game->map);
}
