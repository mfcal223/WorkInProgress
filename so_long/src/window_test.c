#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close_window(t_vars *vars) // Use a struct to pass multiple parameters
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
	void	*mlx;
	void	*win;
	t_data	pic;

	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 800, 600, "MiniLibX Window Test");
	if (!win)
		return (1);
	mlx_hook(win, 17, 0, close_window, mlx); // Close window on exit button
	pic.img = mlx_new_image(mlx, 800, 600);
	pic.addr = mlx_get_data_addr(pic.img, &pic.bits_per_pixel, &pic.line_length,
								&pic.endian);
	my_mlx_pixel_put(&pic, 15, 5, 0x00FF0000);//hex representation of ARGB(0,255,0,0).
	my_mlx_pixel_put(&pic, 5, 5, 0x00FF0000);//hex representation of ARGB(0,255,0,0).
	my_mlx_pixel_put(&pic, 5, 15, 0x00FF0000);//hex representation of ARGB(0,255,0,0).
	mlx_put_image_to_window(mlx, win, pic.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
