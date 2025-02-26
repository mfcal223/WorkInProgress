/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:08 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/26 15:53:36 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
void ft_load_images(t_game *game)
{
    game->img_wall.img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->size.x, &game->size.y);
    game->img_floor.img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &game->size.x, &game->size.y);
    game->img_player.img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->size.x, &game->size.y);
    game->img_collect.img = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &game->size.x, &game->size.y);
    game->img_exit.img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->size.x, &game->size.y);
}
*/

t_game	*initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->path =  NULL;
	game->map = NULL;
	game->array_map = NULL;//array_map
	game->array_ff = NULL;//status_b
	game->size.x = 0;
	game->size.y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->moves = 0;
	game->items = 0;
	game->flag = 0;
	game->imgs.wall.img = NULL;
	game->imgs.floor.img = NULL;
	game->imgs.player.img = NULL;
	game->imgs.collect.img = NULL;
	game->imgs.exit.img = NULL;
	return (game);
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
		ft_printf("Error creating map.\n");//delete - debugging purpouse
		return (1);
	}
	else//delete entire else - debugging purpouse
	{
		ft_printf("map created succesfully.\n");
	}
	//--------------------------------------------
	/*MAKE 1 FUNCTION TO ADMINISTER THE VALIDATION ?????*/
	game = find_player(game);
	if (!game)
	{
		ft_printf("Error: Map needs player starting position.\n");
		ft_free_all(game, 1);
		return (1);
	}
	game = ft_flood(game);
	ft_printf("map flooded succesfully.\n");
	if (ft_check_failed(game, ft_count_obj(game->map)) == 1) 
	{
		ft_printf("Map check failed.\n");
		ft_free_all(game, 1);
		return (1);
	}
	//------------------------------------------------
	my_mlx_init(game); // 7️⃣ Initialize MiniLibX and start game loop */
	ft_free_all(game, 0);
	return (0);
}

/* MAIN */
int main(int ac, char **av)
{
    int i;

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
