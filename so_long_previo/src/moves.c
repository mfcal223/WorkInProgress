/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:53:29 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 10:53:31 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_to_exit(t_game *game)
{
	if (game->items > 0)
		return (0);
	ft_printf("Congratulations! Game completed in %d moves!\n",
		game->moves + 1);
	close_handler(game, "Closing game.\n");
	return (0);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	// 1️⃣ Erase old position
	mlx_put_image_to_window(game->mlx, game->win,//added to stop flickering
		game->imgs.floor.img, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE);
	
		game->array_map[game->player.y][game->player.x] = FLOOR;
	game->array_map[new_y][new_x] = PJ;
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;

	// 3️⃣ Draw new position immediately
	render_player(game);//added to stop flickering

	ft_printf("Moves: %d\n", game->moves);
}

int	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (game->array_map[new_y][new_x] == WALL)
		return (0);
	if (game->array_map[new_y][new_x] == ITEM)
	{
		game->items--;
		game->array_map[new_y][new_x] = FLOOR;
	}
	if (game->array_map[new_y][new_x] == EXIT)
	{
		if (!move_to_exit(game))
			return (0);
	}
	if (game->array_map[new_y][new_x] == ENEMY)
	{
		close_handler(game, "Defeated by the enemy!!!\n");
		return (0);
	}
	update_player_position(game, new_x, new_y);
	return (1);
}
