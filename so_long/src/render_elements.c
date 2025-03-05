/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:00:24 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 11:00:24 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->array_map[y][x] != WALL)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.floor.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->array_map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.wall.img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->array_map[y][x] == ITEM)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.collect.img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->array_map[y][x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.exit.img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game)
{
	if (game->imgs.player.img)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.floor.img, game->player.x * TILE_SIZE,
			game->player.y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.player.img,
			game->player.x * TILE_SIZE,
			game->player.y * TILE_SIZE);
	}
}

void	render_enemies(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < game->enemy_count)
	{
		x = game->enemies[i].x * TILE_SIZE;
		y = game->enemies[i].y * TILE_SIZE;
		mlx_put_image_to_window(game->mlx, game->win,
			game->imgs.floor.img, x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy.img, x,
			y);
		i++;
	}
}
