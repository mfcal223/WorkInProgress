#include "so_long.h"
/* 
void	ft_drawing_imgs(t_game *game, char img, t_coord p)
{
	if (img == '1' && game->imgs.wall != NULL)
		mlx_image_to_window(game->mlx, game->imgs.wall, p.x * 64, p.y * 64);
	if (img != '1' && game->imgs.ocean != NULL)
		mlx_image_to_window(game->mlx, game->imgs.ocean, p.x * 64, p.y * 64);
	if (img == 'P')
	{
		ft_drawing_player(game, p);
		return ;
	}
	if (img == 'C' && game->imgs.collec != NULL)
		mlx_image_to_window(game->mlx, game->imgs.collec, p.x * 64, p.y * 64);
	if (img == 'X' && game->imgs.shark != NULL)
		mlx_image_to_window(game->mlx, game->imgs.shark, p.x * 64, p.y * 64);
	if (img == 'E' && game->imgs.exit_c != NULL)
		mlx_image_to_window(game->mlx, game->imgs.exit_c, p.x * 64, p.y * 64);
}

void	ft_drawing_player(t_game *game, t_coord p)
{
	if (game->course == 'U' && game->counter > 0)
		ft_player_go_up(game, p, game->counter);
	else if (game->course == 'D' && game->counter > 0)
		ft_player_go_down(game, p, game->counter);
	else if (game->course == 'R' && game->counter > 0)
		ft_player_go_right(game, p, game->counter);
	else if (game->course == 'L' && game->counter > 0)
		ft_player_go_left(game, p, game->counter);
	else
		mlx_image_to_window(game->mlx, game->imgs.player, p.x * 64, p.y * 64);
}
*/
/*
void	ft_drawing_map(t_game *game)
{
	t_coord	coord;
	int		j;
	int		i;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->array_map[j][i] != '\n' && game->array_map[j][i] != '\0')
		{
			coord.x = i;
			coord.y = j;
			ft_drawing_imgs(game, game->array_map[j][i], coord);
			i++;
		}
		j++;
	}
	ft_drawing_player(game, game->player);
}


void	ft_game_imgs(t_game *game)
{
	game->imgs.wall = mlx_texture_to_image(game->mlx, game->txts.wall);
	game->imgs.ocean = mlx_texture_to_image(game->mlx, game->txts.ocean);
	game->imgs.player = mlx_texture_to_image(game->mlx, game->txts.player);
	game->imgs.player_d = mlx_texture_to_image(game->mlx, game->txts.player_d);
	game->imgs.player_l = mlx_texture_to_image(game->mlx, game->txts.player_l);
	game->imgs.player_r = mlx_texture_to_image(game->mlx, game->txts.player_r);
	game->imgs.player_u = mlx_texture_to_image(game->mlx, game->txts.player_u);
	game->imgs.shark = mlx_texture_to_image(game->mlx, game->txts.shark);
	game->imgs.collec = mlx_texture_to_image(game->mlx, game->txts.collec);
	game->imgs.exit_c = mlx_texture_to_image(game->mlx, game->txts.exit_c);
	game->imgs.exit_o = mlx_texture_to_image(game->mlx, game->txts.exit_o);
}

void	ft_game_txts(t_game *game)
{
	game->txts.wall = mlx_load_png("./imgs/wall.png");
	game->txts.ocean = mlx_load_png("./imgs/ocean.png");
	game->txts.player = mlx_load_png("./imgs/player.png");
	game->txts.player_u = mlx_load_png("./imgs/player_U.png");
	game->txts.player_d = mlx_load_png("./imgs/player_D.png");
	game->txts.player_l = mlx_load_png("./imgs/player_L.png");
	game->txts.player_r = mlx_load_png("./imgs/player_R.png");
	game->txts.shark = mlx_load_png("./imgs/shark.png");
	game->txts.collec = mlx_load_png("./imgs/collec.png");
	game->txts.exit_c = mlx_load_png("./imgs/exit_c.png");
	game->txts.exit_o = mlx_load_png("./imgs/exit_o.png");
	if (!game->txts.wall || !game->txts.ocean || !game->txts.player
		|| !game->txts.player_u || !game->txts.player_d
		|| !game->txts.player_l || !game->txts.player_r
		|| !game->txts.shark || !game->txts.collec
		|| !game->txts.exit_c || !game->txts.exit_o)
	{
		ft_map_error("The textures could not be loaded..\n");
		ft_free_all(game, 1);
		exit(1);
	}
}*/

/*
void	ft_key_press(struct mlx_key_image key_image, void *date)
{
	t_game	*game;

	game = date;
	game = ft_find_player(game);
	if (key_image.key == MLX_KEY_UP && ft_key_check(game) == 1)
		ft_move_player_up(game, game->player.y, game->player.x);
	if (key_image.key == MLX_KEY_DOWN && ft_key_check(game) == 2)
		ft_move_player_down(game, game->player.y, game->player.x);
	if (key_image.key == MLX_KEY_LEFT && ft_key_check(game) == 3)
		ft_move_player_left(game, game->player.y, game->player.x);
	if (key_image.key == MLX_KEY_RIGHT && ft_key_check(game) == 4)
		ft_move_player_right(game, game->player.y, game->player.x);
	if (key_image.key == MLX_KEY_ESCAPE && ft_key_check(game) == 5)
	{
		mlx_close_window(game->mlx);
		return ;
	}
}*/

/* //KEY HANDLERS */
/*int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC key
        close_window(game);
    return (0);
}*/
/*
int close_window(t_game *game)
{
    // Destroy the image first
    if (game->imgs.img)
        mlx_destroy_image(game->mlx, game->imgs.img);
    // Then destroy the window
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    // Finally cleanup MLX itself
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
        exit(0);
    return (0);
}*/

/* //IMAGE PUSHING
void	my_mlx_pixel_put(t_pixel *img, int x, int y, int color)
{
	char	*dst;

	// Add bounds checking
	if (x < 0 || y < 0 || x >= W_WIDTH || y >= W_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
*/
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->array_map[y])
	{
		x = 0;
		while (game->array_map[y][x])
		{
			void *img = NULL;

			if (game->array_map[y][x] == WALL)
				img = game->imgs.wall.img;
			else if (game->array_map[y][x] == FLOOR)
				img = game->imgs.floor.img;
			else if (game->array_map[y][x] == PJ)
				img = game->imgs.player.img;
			else if (game->array_map[y][x] == EXIT)
				img = game->imgs.exit.img;
			else if (game->array_map[y][x] == ITEM)
				img = game->imgs.collect.img;

			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->imgs.wall.img = mlx_xpm_file_to_image(game->mlx, "textures/BG_2.xpm", 64, 64);
	game->imgs.floor.img = mlx_xpm_file_to_image(game->mlx, "textures/BG_6.xpm", 64, 64);
	game->imgs.player.img = mlx_xpm_file_to_image(game->mlx, "textures/player_up.xpm", 32, 32);
	game->imgs.collect.img = mlx_xpm_file_to_image(game->mlx, "textures/box.xpm", 32, 32);
	game->imgs.exit.img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", 64, 64);
	game->imgs.wall.addr = mlx_get_data_addr(game->imgs.wall.img, &game->imgs.wall.bits_per_pixel,
											 &game->imgs.wall.line_length, &game->imgs.wall.endian);
	game->imgs.floor.addr = mlx_get_data_addr(game->imgs.floor.img, &game->imgs.floor.bits_per_pixel,
											  &game->imgs.floor.line_length, &game->imgs.floor.endian);
	game->imgs.player.addr = mlx_get_data_addr(game->imgs.player.img, &game->imgs.player.bits_per_pixel,
											   &game->imgs.player.line_length, &game->imgs.player.endian);
	game->imgs.collect.addr = mlx_get_data_addr(game->imgs.collect.img, &game->imgs.collect.bits_per_pixel,
												&game->imgs.collect.line_length, &game->imgs.collect.endian);
	game->imgs.exit.addr = mlx_get_data_addr(game->imgs.exit.img, &game->imgs.exit.bits_per_pixel,
											 &game->imgs.exit.line_length, &game->imgs.exit.endian);
	if (!game->imgs.wall.img || !game->imgs.floor.img || !game->imgs.player.img ||
		!game->imgs.collect.img || !game->imgs.exit.img)
	{
		ft_printf("Error: Failed to load textures\n");
		close_window(game);
	}
}

void	my_mlx_init(t_game *game)
{
	game = find_player(game);
	game->mlx = mlx_init();
	if (!game || !game->mlx)
	{
		ft_free_all(game, 1);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, 800, 600, "So_Long 2D VideoGame");
	if (!game->win)
	{
		close_window(&game);//??????
        ft_free_all(game, 1);
		exit (1);
	}

    load_textures(game);  // Load images
	render_map(game);     // Render the map

	mlx_hook(game->win, 17, 0, close_window, game); // X button close
	mlx_key_hook(game->win, handle_keypress, game); // Keyboard hooks

	mlx_loop(game->mlx);
}
/*
ADAPTA MY_MLX_IMAGE EN RENDER. REVISAR INCONSISTENCIAS DE ESTRUCTURAS EN CLOSE WINDOW.
MEJORAR KEY HOOK HANDLING
*/


