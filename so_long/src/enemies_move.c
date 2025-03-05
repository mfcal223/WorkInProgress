/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:50:42 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/05 14:27:01 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    choose_enemy_move(t_game *game, int *new_x, int *new_y, int index)
{
    // Get current position from enemy_pos array
    *new_x = game->enemy_pos[index].pos.x;
    *new_y = game->enemy_pos[index].pos.y;

    // Your existing pseudo-random movement logic 
    // (using time, position, or other values for randomization)
    int move_pattern;
    
    // Example: Use enemy index, timer and position to create pseudo-random pattern
    move_pattern = (game->enemy_timer + index + *new_x + *new_y) % 4;

    // Apply movement based on pattern
    if (move_pattern == 0 && *new_x < game->size.x - 1)
        (*new_x)++;           // Move right
    else if (move_pattern == 1 && *new_x > 1)
        (*new_x)--;           // Move left
    else if (move_pattern == 2 && *new_y < game->size.y - 1)
        (*new_y)++;           // Move down
    else if (move_pattern == 3 && *new_y > 1)
        (*new_y)--;           // Move up
}

void	update_enemy_pos(t_game *game, int index, int new_x, int new_y)
{
	// Update floor at old position
	mlx_put_image_to_window(game->mlx, game->win, game->imgs.floor.img,
		game->enemy_pos[index].pos.x * TILE_SIZE, game->enemy_pos[index].pos.y
		* TILE_SIZE);
	// Update map array
	game->array_map[game->enemy_pos[index].pos.y][game->enemy_pos[index].pos.x] = FLOOR;
	game->array_map[new_y][new_x] = ENEMY;
	// Update grid position
	game->enemy_pos[index].pos.x = new_x;
	game->enemy_pos[index].pos.y = new_y;
	// Set moving flag to trigger smooth animation
	game->enemy_pos[index].moving = 1;
	// Check for collision with player
	if (new_x == game->player_pos.pos.x && new_y == game->player_pos.pos.y)
		close_handler(game, "Defeated by the enemy!!!\n");
}

void	move_enemies(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;
	int	can_move;

	game->enemy_timer++;
	if (game->enemy_timer < 3000)
		return ;
	game->enemy_timer = 0;
	i = 0;
	while (i < game->enemy_count)
	{
		// Only move if enemy isn't already moving
		if (!game->enemy_pos[i].moving)
		{
			new_x = game->enemy_pos[i].pos.x;
			new_y = game->enemy_pos[i].pos.y;
			// Get new position
			choose_enemy_move(game, &new_x, &new_y, i);
			// Check if new position is valid
			can_move = (game->array_map[new_y][new_x] != WALL
					&& game->array_map[new_y][new_x] != ITEM
					&& game->array_map[new_y][new_x] != EXIT
					&& game->array_map[new_y][new_x] != ENEMY);
			if (can_move)
				update_enemy_pos(game, i, new_x, new_y);
		}
		i++;
	}
}
/*

int	valid_move(char **array_map, int x, int y)
{
	return (array_map[y][x] == FLOOR || array_map[y][x] == PJ);
}

int	select_enemy_direction(t_game *game, int i, int attempts)
{
	return ((game->moves + game->enemy_timer + i + attempts) % 4);
}
void	choose_enemy_move(t_game *game, int *new_x, int *new_y, int i)
{
	int	dir;
	int	attempts;

	attempts = 0;
	while (attempts < 4)
	{
		dir = select_enemy_direction(game, i, attempts);
		if (dir == 0 && valid_move(game->array_map, *new_x - 1, *new_y))
			(*new_x)--;
		else if (dir == 1 && valid_move(game->array_map, *new_x + 1, *new_y))
			(*new_x)++;
		else if (dir == 2 && valid_move(game->array_map, *new_x, *new_y - 1))
			(*new_y)--;
		else if (dir == 3 && valid_move(game->array_map, *new_x, *new_y + 1))
			(*new_y)++;
		else
		{
			attempts++;
			continue ;
		}
		break ;
	}
}
	
void	update_enemy_pos(t_game *game, int i, int new_x, int new_y)
{
	if (game->array_map[new_y][new_x] == PJ)
	{
		close_handler(game, "An enemy found you!!!\n");
		return ;
	}
	game->array_map[game->enemies[i].y][game->enemies[i].x] = FLOOR;
	game->array_map[new_y][new_x] = ENEMY;
	game->enemies[i].x = new_x;
	game->enemies[i].y = new_y;
	// 4️⃣ Draw new enemy position immediately
	//render_enemies(game);
}

void	move_enemies(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;

	game->enemy_timer++;
	if (game->enemy_timer < 3000)
		return ;
	game->enemy_timer = 0;
	i = 0;
	while (i < game->enemy_count)
	{
		new_x = game->enemies[i].x;
		new_y = game->enemies[i].y;
		choose_enemy_move(game, &new_x, &new_y, i);
		update_enemy_pos(game, i, new_x, new_y);
		i++;
	}
}
*/
