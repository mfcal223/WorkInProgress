/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/03 10:21:13 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 10:21:18 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	count_enemies(t_game *game)
{
	int x;
	int y;

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
	int x;
	int y;
	int count;

	y = 0;
	count = 0;
	while (y < game->size.y)
	{
		x = 0;
		while (x < game->size.x)
		{
			if (game->array_map[y][x] == ENEMY)
			{
				game->enemy_pos[count].pos.x = x;
				game->enemy_pos[count].pos.y = y;
				// Initialize window position
				game->enemy_pos[count].win_pos.x = x * TILE_SIZE;
				game->enemy_pos[count].win_pos.y = y * TILE_SIZE;
				// Initialize movement state
				game->enemy_pos[count].moving = 0;
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
        game->enemy_pos = NULL;
        return;
    }
    game->enemy_pos = malloc(sizeof(t_posit) * game->enemy_count);
    if (!game->enemy_pos)
		return ;
	store_enemies(game);
}
/*int i;//debug
ft_printf("Total enemies found: %d\n", game->enemy_count);//debug
i = 0;//debug
while (i < game->enemy_count)
{
ft_printf("Enemy %d at: (%d, %d)\n", i, game->enemies[i].x,
	game->enemies[i].y);
i++;
}*/
/*void	move_enemies(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;

	game->enemy_timer++;
	if (game->enemy_timer < 1000)
		return ;
	game->enemy_timer = 0;
	i = 0;
	while (i < game->enemy_count)
	{
		new_x = game->enemies[i].x;
		new_y = game->enemies[i].y;
		if (game->array_map[new_y][new_x - 1] == FLOOR
			|| game->array_map[new_y][new_x - 1] == PJ)
			new_x--;
		else if (game->array_map[new_y][new_x + 1] == FLOOR
			&& game->array_map[new_y][new_x - 1] == PJ)
			new_x++;
		update_enemy_pos(game, i, new_x, new_y);
		i++;
	}
}*/
