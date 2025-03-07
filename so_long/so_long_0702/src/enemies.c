/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:21:13 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 10:21:18 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_previous_enemy(t_game *game, t_coord pos)
{
	if (pos.x >= 0 && pos.y >= 0)
	{
		if (game->array_map[pos.y][pos.x] == WALL)
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.wall.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
		else if (game->array_map[pos.y][pos.x] == EXIT)
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.exit.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
		else if (game->array_map[pos.y][pos.x] == ITEM)
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.collect.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.floor.img, pos.x * TILE_SIZE, pos.y * TILE_SIZE);
	}
}

void	render_enemies(t_game *game)
{
	static t_coord	prev_pos[100];
	int				i;

	i = 0;
	while (i < game->enemy_count)
	{
		clear_previous_enemy(game, prev_pos[i]);
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy.img,
			game->enemies[i].x * TILE_SIZE, game->enemies[i].y * TILE_SIZE);
		prev_pos[i] = game->enemies[i];
		i++;
	}
}

void	count_enemies(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->enemy_count = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->array_map[y][x] == ENEMY)
				game->enemy_count++;
			x++;
		}
		y++;
	}
}

void	store_enemies(t_game *game)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->array_map[y][x] == ENEMY)
			{
				game->enemies[count].x = x;
				game->enemies[count].y = y;
				count++;
			}
			x++;
		}
		y++;
	}
}

void	find_enemies(t_game *game)
{
	count_enemies(game);
	if (game->enemy_count == 0)
	{
		game->enemies = NULL;
		return ;
	}
	game->enemies = malloc(sizeof(t_coord) * game->enemy_count);
	if (!game->enemies)
		return ;
	store_enemies(game);
}
