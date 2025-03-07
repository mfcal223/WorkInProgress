/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/03/07 14:38:55 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/07 14:38:55 by mcalciat         ###   ########.fr       */
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
			if (game->array_map[y][x] == WALL)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.wall.img, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.floor.img, x * TILE_SIZE, y * TILE_SIZE);
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
	if (game->array_map[game->prev_player.y][game->prev_player.x] == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall.img,
			game->prev_player.x * TILE_SIZE, game->prev_player.y * TILE_SIZE);
	else if (game->array_map[game->prev_player.y][game->prev_player.x] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.exit.img,
			game->prev_player.x * TILE_SIZE, game->prev_player.y * TILE_SIZE);
	else if (game->array_map[game->prev_player.y][game->prev_player.x] == ITEM)
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.collect.img,
			game->prev_player.x * TILE_SIZE, game->prev_player.y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.floor.img,
			game->prev_player.x * TILE_SIZE, game->prev_player.y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.player.img,
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	game->prev_player.x = game->player.x;
	game->prev_player.y = game->player.y;
}
/* ESTAS FUNCIONES FUNCIONAN !!!
void	render_player(t_game *game)
{
	static int	prev_x;
	static int	prev_y;

	prev_x = -1;
	prev_y = -1;
	if (prev_x >= 0 && prev_y >= 0)
	{
		if (game->array_map[prev_y][prev_x] == WALL)
			mlx_put_image_to_window(game->mlx, game->win, game->imgs.wall.img,
				prev_x * TILE_SIZE, prev_y * TILE_SIZE);
		else if (game->array_map[prev_y][prev_x] == EXIT)
			mlx_put_image_to_window(game->mlx, game->win, game->imgs.exit.img,
				prev_x * TILE_SIZE, prev_y * TILE_SIZE);
		else if (game->array_map[prev_y][prev_x] == ITEM)
			mlx_put_image_to_window(game->mlx, game->win,
				game->imgs.collect.img, prev_x * TILE_SIZE, prev_y
				* TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->imgs.floor.img,
				prev_x * TILE_SIZE, prev_y * TILE_SIZE);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.player.img,
		game->player.x * TILE_SIZE, game->player.y * TILE_SIZE);
	prev_x = game->player.x;
	prev_y = game->player.y;
}

void	render_enemies(t_game *game)
{
	static t_coord	prev_pos[100];
	int				i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (prev_pos[i].x >= 0 && prev_pos[i].y >= 0)
		{
			if (game->array_map[prev_pos[i].y][prev_pos[i].x] == WALL)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.wall.img, prev_pos[i].x * TILE_SIZE,
					prev_pos[i].y * TILE_SIZE);
			else if (game->array_map[prev_pos[i].y][prev_pos[i].x] == EXIT)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.exit.img, prev_pos[i].x * TILE_SIZE,
					prev_pos[i].y * TILE_SIZE);
			else if (game->array_map[prev_pos[i].y][prev_pos[i].x] == ITEM)
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.collect.img, prev_pos[i].x * TILE_SIZE,
					prev_pos[i].y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->imgs.floor.img, prev_pos[i].x * TILE_SIZE,
					prev_pos[i].y * TILE_SIZE);
		}
		mlx_put_image_to_window(game->mlx, game->win, game->imgs.enemy.img,
			game->enemies[i].x * TILE_SIZE, game->enemies[i].y * TILE_SIZE);
		prev_pos[i] = game->enemies[i];
		i++;
	}
}
*/
/*
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
}*/
