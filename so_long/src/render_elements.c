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

void    render_player(t_game *game)
{
    // Calculate target position
    int target_x = game->player_pos.pos.x * TILE_SIZE;
    int target_y = game->player_pos.pos.y * TILE_SIZE;
    
    // Move smoothly towards target if player is moving
    if (game->player_pos.moving)
    {
        if (game->player_pos.win_pos.x < target_x)
            game->player_pos.win_pos.x += 1;
        if (game->player_pos.win_pos.x > target_x)
            game->player_pos.win_pos.x -= 1;
        if (game->player_pos.win_pos.y < target_y)
            game->player_pos.win_pos.y += 1;
        if (game->player_pos.win_pos.y > target_y)
            game->player_pos.win_pos.y -= 1;

        // Check if we reached the target
        if (game->player_pos.win_pos.x == target_x && 
            game->player_pos.win_pos.y == target_y)
            game->player_pos.moving = 0;
    }
    // Render at current window position
    mlx_put_image_to_window(game->mlx, game->win,
        game->imgs.player.img,
        game->player_pos.win_pos.x,
        game->player_pos.win_pos.y);
}

void    render_enemies(t_game *game)
{
    int i;
    int target_x;
    int target_y;

    i = 0;
    while (i < game->enemy_count)
    {
        // Calculate target position
        target_x = game->enemy_pos[i].pos.x * TILE_SIZE;
        target_y = game->enemy_pos[i].pos.y * TILE_SIZE;
        // Move smoothly towards target if enemy is moving
        if (game->enemy_pos[i].moving)
        {
            if (game->enemy_pos[i].win_pos.x < target_x)
                game->enemy_pos[i].win_pos.x += 1;
            if (game->enemy_pos[i].win_pos.x > target_x)
                game->enemy_pos[i].win_pos.x -= 1;
            if (game->enemy_pos[i].win_pos.y < target_y)
                game->enemy_pos[i].win_pos.y += 1;
            if (game->enemy_pos[i].win_pos.y > target_y)
                game->enemy_pos[i].win_pos.y -= 1;

            // Check if we reached the target
            if (game->enemy_pos[i].win_pos.x == target_x
				&& game->enemy_pos[i].win_pos.y == target_y)
                game->enemy_pos[i].moving = 0;
        }
        // Render at current window position
        mlx_put_image_to_window(game->mlx, game->win,
            game->imgs.enemy.img, game->enemy_pos[i].win_pos.x,
            game->enemy_pos[i].win_pos.y);
        i++;
    }
}

/*void	render_player(t_game *game)
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
}*/
/*
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
}*/
