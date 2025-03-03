/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:08 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 15:13:53 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_handler(t_game *game, char *message)
{
	ft_printf("%s\n", message);
	if (!game)
	{
		return (1);
	}
	close_window(game);
	return (0);
}

t_game	*initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->path = NULL;
	game->map = NULL;
	game->array_map = NULL;
	game->array_ff = NULL;
	game->size.x = 0;
	game->size.y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->moves = 0;
	game->items = 0;
	game->flag = 0;
	game->enemy_timer = 0;
	game->imgs.wall.img = NULL;
	game->imgs.floor.img = NULL;
	game->imgs.player.img = NULL;
	game->imgs.collect.img = NULL;
	game->imgs.exit.img = NULL;
	return (game);
}

int	validate_map(t_game *game)
{
	game = find_player(game);
	find_enemies(game);
	if (!game)
	{
		close_handler(game, "Map needs player starting position.\n");
		return (1);
	}
	game = map_validation(game);
	if (ft_check_failed(game, count_objects(game->map)) == 1)
	{
		close_handler(game, "Map check failed.\n");
		return (1);
	}
	return (0);
}

/* START THE GAME, LOAD THE MAP , CHECK MAP IS VALID, AND START GAME LOOP */
int	game_start(char *map)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (1);
	game = initialize_game(game);
	game->path = map;
	if (build_map(&game) == 1)
	{
		close_handler(game, "Failed to create map.\n");
		return (1);
	}
	if (validate_map(game) == 1)
		return (1);
	my_mlx_init(game);
	return (0);
}

/* MAIN */
int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
	{
		ft_printf("Wrong input: try ./so_long </maps/map01.ber>\n");
		return (1);
	}
	if (ac == 2)
	{
		if (check_extension(av[1]) == 1)
		{
			ft_printf("Map file is not *.ber.\n");
			return (1);
		}
		i = game_start(av[1]);
		if (i == 1)
			return (1);
	}
	return (0);
}
/*
int	game_start(char *map)
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (1);
	game = initialize_game(game);
	game->path = map;
	if (build_map(&game) == 1)
	{
		close_handler(game, "Failed to create map.\n");
		return (1);
	}
	game = find_player(game);
	find_enemies(game);
	if (!game)
	{
		close_handler(game, "Map needs player starting position.\n");
		return (1);
	}
	game = map_validation(game);
	if (ft_check_failed(game, count_objects(game->map)) == 1)
	{
		close_handler(game, "Map check failed.\n");
		return (1);
	}
	my_mlx_init(game);
	return (0);
}
*/
