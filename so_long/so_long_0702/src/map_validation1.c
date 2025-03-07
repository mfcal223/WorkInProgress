/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:28 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 14:52:18 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cell	count_objects(t_map *map)
{
	t_cell	objects;
	int		i;

	objects.player = 0;
	objects.item = 0;
	objects.exit = 0;
	while (map)
	{
		i = 0;
		while (map->map[i])
		{
			if (map->map[i] == 'P')
				objects.player++;
			if (map->map[i] == 'C')
				objects.item++;
			if (map->map[i] == 'E')
				objects.exit++;
			i++;
		}
		map = map->next;
	}
	return (objects);
}

t_game	**cell_objects(t_game **game, char check)
{
	if (check == ITEM)
	{
		(*game)->cell.item++;
		(*game)->items++;
	}
	if (check == PJ)
		(*game)->cell.player++;
	if (check == EXIT)
		(*game)->cell.exit++;
	return (game);
}

t_game	**path_valid_ff(char **tab, t_coord size, t_coord curr, t_game **game)
{
	if (curr.y < 0 || curr.y >= size.y || curr.x < 0 || curr.x >= size.x
		|| tab[curr.y][curr.x] == '1' || tab[curr.y][curr.x] == 'F')
		return (game);
	if (curr.x >= (int)ft_strlen(tab[curr.y]))
		return (game);
	if (tab[curr.y][curr.x] == 'E')
	{
		tab[curr.y][curr.x] = 'F';
		(*game)->cell.exit = 1;
		return (game);
	}
	game = cell_objects(game, tab[curr.y][curr.x]);
	tab[curr.y][curr.x] = 'F';
	game = path_valid_ff(tab, size, (t_coord){curr.x - 1, curr.y}, game);
	game = path_valid_ff(tab, size, (t_coord){curr.x + 1, curr.y}, game);
	game = path_valid_ff(tab, size, (t_coord){curr.x, curr.y - 1}, game);
	game = path_valid_ff(tab, size, (t_coord){curr.x, curr.y + 1}, game);
	return (game);
}

t_game	*map_validation(t_game *game)
{
	game->cell.player = 0;
	game->cell.item = 0;
	game->cell.exit = 0;
	game = *path_valid_ff(game->array_ff, game->size, game->player, &game);
	return (game);
}

/*finds position of Player and updates those coords int the game struct */
t_game	*find_player(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	game->player.x = 0;
	game->player.y = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->array_map[j][i] != '\n' && game->array_map[j][i] != '\0')
		{
			if (game->array_map[j][i] == 'P')
			{
				game->player.x = i;
				game->player.y = j;
				return (game);
			}
			i++;
		}
		j++;
	}
	return (game);
}
