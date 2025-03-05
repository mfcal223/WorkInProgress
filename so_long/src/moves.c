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

void    find_player_position(char **map, int *x, int *y)
{
    *y = 0;
    while (map[*y])
    {
        *x = 0;
        while (map[*y][*x])
        {
            if (map[*y][*x] == PJ)
                return;
            (*x)++;
        }
        (*y)++;
    }
}

void    find_enemy_position(char **map, int *x, int *y, int index)
{
    int count;

    count = 0;
    *y = 0;
    while (map[*y])
    {
        *x = 0;
        while (map[*y][*x])
        {
            if (map[*y][*x] == ENEMY)
            {
                if (count == index)
                    return;
                count++;
            }
            (*x)++;
        }
        (*y)++;
    }
}

void    exit_error(t_game *game, char *message)
{
    ft_printf("Error\n%s\n", message);
    // Free any allocated memory
    if (game)
    {
        // Add your cleanup code here
        // free_game(game);
    }
    exit(1);
}

int	move_to_exit(t_game *game)
{
	if (game->items > 0)
		return (0);
	ft_printf("Congratulations! Game completed in %d moves!\n",
		game->moves + 1);
	close_handler(game, "Closing game.\n");
	return (0);
}

void    update_player_position(t_game *game, int new_x, int new_y)
{
    // 1️⃣ Update the floor at old position
    mlx_put_image_to_window(game->mlx, game->win,
        game->imgs.floor.img, 
        game->player_pos.pos.x * TILE_SIZE,
        game->player_pos.pos.y * TILE_SIZE);
    
    // 2️⃣ Update map array
    game->array_map[game->player_pos.pos.y][game->player_pos.pos.x] = FLOOR;
    game->array_map[new_y][new_x] = PJ;
    
    // 3️⃣ Update grid position
    game->player_pos.pos.x = new_x;
    game->player_pos.pos.y = new_y;
    
    // 4️⃣ Set moving flag to trigger smooth animation
    game->player_pos.moving = 1;
    
    // 5️⃣ Update move counter
    game->moves++;
    ft_printf("Moves: %d\n", game->moves);
    
    // Note: We don't need to render_player here anymore
    // The render_frame function will handle the smooth movement
}

int move_player(t_game *game, int dx, int dy)
{
    int new_x;
    int new_y;

    // Calculate new position based on current grid position
    new_x = game->player_pos.pos.x + dx;
    new_y = game->player_pos.pos.y + dy;

    // Check for collisions and interactions
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

    // Only update position if player isn't currently moving
    if (!game->player_pos.moving)
        update_player_position(game, new_x, new_y);

    return (1);
}
/*
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
	//render_player(game);//added to stop flickering

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
}*/
