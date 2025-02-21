#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// Add bounds checking
	if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
/* in oceano video, dst is an INT */

int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->pic.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}
int	main(void)
{
	t_vars	vars;

	// Initialize MLX
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	// Create window
	vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Window Test");
	if (!vars.win)
	{
		/*mlx_destroy_display(vars.mlx);
		free(vars.mlx);*/
		close_window(vars);
		return (1);
	}
	// Create image
	vars.pic.img = mlx_new_image(vars.mlx, 800, 600);
	if (!vars.pic.img)
	{ // can I just call close_window() ???
		/*mlx_destroy_window(vars.mlx, vars.win);
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);*/
		close_window(vars);
		return (1);
	}
	// Set up event hooks
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	// Get image data
	vars.pic.addr = mlx_get_data_addr(vars.pic.img, &vars.pic.bits_per_pixel,
			&vars.pic.line_length, &vars.pic.endian);
	// Draw pixels
	my_mlx_pixel_put(&vars.pic, 15, 5, 0x00FF0000); // red
	my_mlx_pixel_put(&vars.pic, 5, 5, 0x0000FF00);  // green
	my_mlx_pixel_put(&vars.pic, 5, 15, 0x000000FF); // blue
	// Put image to window
	mlx_put_image_to_window(vars.mlx, vars.win, vars.pic.img, 0, 0);
	// Start event loop
	mlx_loop(vars.mlx);
	close_window(vars);
	return (0);
}
