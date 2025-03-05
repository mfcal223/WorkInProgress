/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:00:36 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 15:06:11 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* This function will create the map and validate it. */
int	init_map(t_game *game)
{
	game->map = create_map(game);
	if (!game->map)
	{
		close_handler(game, "Fail to create map.\n");
		return (1);
	}
	game->size.x = map_x_width(game->map, game);
	game->size.y = map_y_heigth(game->map, game);
	if (game->size.x == -1 || game->size.y == -1)
		return (1);
	return (0);
}

/* This function will create array_map and array_ff. */
int	dup_map_arrays(t_game *game)
{
	game->array_map = duplicate_map(game);
	if (!game->array_map)
	{
		close_handler(game, "Fail to create array_map.\n");
		return (1);
	}
	game->array_ff = duplicate_map(game);
	if (!game->array_ff)
	{
		close_handler(game, "Fail to create array_ff.\n");
		return (1);
	}
	return (0);
}

int	build_map(t_game **game)
{
	t_game	*temp;

	temp = *game;
	if (init_map(temp) == 1)
		return (1);
	if (dup_map_arrays(temp) == 1)
		return (1);
	*game = temp;
	return (0);
}

/*int	build_map(t_game **game)
{
	t_game	*temp;

	temp = *game;
	temp->map = create_map_array(temp);
	if (!temp->map)
	{
		close_handler(*game, "Fail to create map.\n");
		return (1);
	}
	temp->size.x = map_x_width(temp->map, *game);
	temp->size.y = map_y_heigth(temp->map, *game);
	if (temp->size.x == -1 || temp->size.y == -1)
		return (1);
	temp->array_map = duplicate_map(temp);
	if (!temp->array_map)
	{
		close_handler(*game, "Fail to create array_map.\n");
		return (1);
	}
	temp->array_ff = duplicate_map(temp);
	if (!temp->array_ff)
	{
		close_handler(*game, "Fail to create array_ff.\n");
		return (1);
	}
	*game = temp;
	return (0);
}*/
/* they read a map file, check its content, compute its dimensions,
 and create duplicate representations of the map for later use (for
 instance, for gameplay logic or pathfinding). */
