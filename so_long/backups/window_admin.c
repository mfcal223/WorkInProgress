#include "so_long.h"

/* KEY HANDLERS */
int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307) // ESC key
        close_window(game);
    return (0);
}

int close_window(t_game *game)
{
    // Destroy the image first
    if (game->pic.img)
        mlx_destroy_image(game->mlx, game->pic.img);
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
}
/* IMAGE PUSHING */
void	my_mlx_pixel_put(t_pixel *img, int x, int y, int color)
{
	char	*dst;

	// Add bounds checking
	if (x < 0 || y < 0 || x >= W_WIDTH || y >= W_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bppix / 8));
	*(unsigned int *)dst = color;
}
/* in flooro video, dst is an INT */
/* WINDOW MANAGEMENT */
int	window_init(char *map)
{
	t_game	game;

	// Initialize MLX
	game.mlx = mlx_init();
	if (!game.mlx)
		return (1);
	// Create window
	game.win = mlx_new_window(game.mlx, 800, 600, "MiniLibX Window Test");
	if (!game.win)
	{
		close_window(&game);
		return (1);
	}
/*	POR CAMBIAR NOMBRE DE VARIABLES Y ORGANIZACION DE ESTRUCTURAS, LOS NOMBRES DE ESTAS 
	VARIABLES SON DISTINTOS - Y ADEMAS SE CREO UNA ESTRUCTURA INTERMEDIA ("S_IMGS") A COMO 
	ESTABA ORGANIZADO ANTES. HAY QUE REVISAR COMO UPDATEAR ESTO!!!
	// Create image
	game.pic.img = mlx_new_image(game.mlx, 800, 600);
	if (!game.pic.img)
	{
		close_window(&game);
		return (1);
	}
	// Set up event hooks
	mlx_hook(game.win, 17, 0, close_window, &game); //X button handler
	mlx_key_hook(game.win, handle_keypress, &game); // Handle ESC key
    // Get image image
	game.pic.addr = mlx_get_image_addr(game.pic.img, &game.pic.bppix,
			&game.pic.line_len, &game.pic.endian);
	// Draw pixels
	my_mlx_pixel_put(&game.pic, 15, 5, 0x00FF0000); // red
	my_mlx_pixel_put(&game.pic, 5, 5, 0x0000FF00);  // green
	my_mlx_pixel_put(&game.pic, 5, 15, 0x000000FF); // blue
	// Put image to window
	mlx_put_image_to_window(game.mlx, game.win, game.pic.img, 0, 0);
	*/
	// Start event loop
	mlx_loop(game.mlx);
	close_window(&game);
	return (0);
}

// ======================================================================= //
/* 
void	ft_drawing_imgs(t_game *game, char img, t_coord p)
{
	if (img == '1' && game->imgs.wall != NULL)
		mlx_image_to_window(game->mlx, game->imgs.wall, p.x * 64, p.y * 64);
	if (img != '1' && game->imgs.floor != NULL)
		mlx_image_to_window(game->mlx, game->imgs.floor, p.x * 64, p.y * 64);
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
	game->imgs.floor = mlx_texture_to_image(game->mlx, game->txts.floor);
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
	game->txts.floor = mlx_load_png("./imgs/floor.png");
	game->txts.player = mlx_load_png("./imgs/player.png");
	game->txts.player_u = mlx_load_png("./imgs/player_U.png");
	game->txts.player_d = mlx_load_png("./imgs/player_D.png");
	game->txts.player_l = mlx_load_png("./imgs/player_L.png");
	game->txts.player_r = mlx_load_png("./imgs/player_R.png");
	game->txts.shark = mlx_load_png("./imgs/shark.png");
	game->txts.collec = mlx_load_png("./imgs/collec.png");
	game->txts.exit_c = mlx_load_png("./imgs/exit_c.png");
	game->txts.exit_o = mlx_load_png("./imgs/exit_o.png");
	if (!game->txts.wall || !game->txts.floor || !game->txts.player
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