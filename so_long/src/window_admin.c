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
/*	POR CAMBIAR NOMBRE DE VARIABLES Y ORGANIZACION DE ESTRUCTURAS, LOS NOMBRES DE ESTAS 
	VARIABLES SON DISTINTOS - Y ADEMAS SE CREO UNA ESTRUCTURA INTERMEDIA ("S_IMGS") A COMO 
	ESTABA ORGANIZADO ANTES. HAY QUE REVISAR COMO UPDATEAR ESTO!!!*/
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
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/* in oceano video, dst is an INT */
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
	game.pic.addr = mlx_get_image_addr(game.pic.img, &game.pic.bits_per_pixel,
			&game.pic.line_length, &game.pic.endian);
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
