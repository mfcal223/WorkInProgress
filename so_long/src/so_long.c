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

t_game	*ft_initialize_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->path =  NULL;
	game->map = NULL;
	game->array_map = NULL;
	game->array_ff = NULL;
	game->size.x = 0;
	game->size.y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->moves = 0;
	game->items = 0;
	//game->flag = 0;
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

	game = ft_calloc(sizeof(t_game), 1);// CHECK EL FREE!!!
	if (!game)
		return (1);
	game = ft_initialize_game(game);  // 1️⃣ Initialize game structure
	game->path = path;
	if (ft_map(&game) == 1) // 2️⃣ Load and validate map
		return (FAILURE);
		
/*	game = ft_find_ship(game); // 3️⃣ Locate player (P)
	game = ft_flood(game); // 4️⃣ Flood-fill to check map accessibility
	game->status_b = ft_free_status(game->status_b, game->size.y); // 5️⃣ Cleanup redundant status map
	if (ft_check_failed(game, ft_count_obj(game->map)) == FAILURE) // 6️⃣ Validate map structure & objects
	{
		ft_free_all(game, 1);
		return (FAILURE);
	}
	ft_mlx_init(game); // 7️⃣ Initialize MiniLibX and start game loop
	ft_free_all(game, 0);  // 8️⃣ Free memory on exit
	return (SUCCESS);
*/
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
