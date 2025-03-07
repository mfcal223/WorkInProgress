/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:49:25 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/07 15:01:19 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	move_enemies(t_game *game)
{
	int			i;
	int			new_x;
	int			new_y;

	game->enemy_timer++;
	if (game->enemy_timer < 20)
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
