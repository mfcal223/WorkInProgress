/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_load_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:53:21 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/05 15:51:10 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_frame(t_game *game)
{
	char	*moves_str;
    
	//mlx_clear_window(game->mlx, game->win);  // Clears only ONCE per frame
	move_enemies(game);
	render_map(game);
	render_exit(game);
	render_collectibles(game);
	render_player(game);
	render_enemies(game);
	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return (0);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 60, 20, 0xFFFFFF, moves_str);
	free(moves_str);
	//mlx_do_sync(game->mlx);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	int	moved;

	moved = 0;
	if (keycode == KEY_ESC)
		close_handler(game, "Exit game via ESC-key.\n");
	else if (keycode == KEY_W || keycode == KEY_UP)
		moved = move_player(game, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		moved = move_player(game, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		moved = move_player(game, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		moved = move_player(game, 1, 0);
	if (moved)
		render_frame(game);
	return (0);
}

void	load_game_images(t_game *game)
{
	int	size_x;
	int	size_y;

	game->imgs.wall.img = mlx_xpm_file_to_image(game->mlx,
			"imgs/wall.xpm", &size_x, &size_y);
	game->imgs.floor.img = mlx_xpm_file_to_image(game->mlx,
			"imgs/BG_6.xpm", &size_x, &size_y);
	game->imgs.player.img = mlx_xpm_file_to_image(game->mlx,
			"imgs/pj_bg.xpm", &size_x, &size_y);
	game->imgs.collect.img = mlx_xpm_file_to_image(game->mlx,
			"imgs/BG_2.xpm", &size_x, &size_y);
	game->imgs.exit.img = mlx_xpm_file_to_image(game->mlx,
			"imgs/door_wbg.xpm", &size_x, &size_y);
	game->imgs.enemy.img = mlx_xpm_file_to_image(game->mlx,
			"imgs/enemy1.xpm", &size_x, &size_y);
	if (!game->imgs.wall.img || !game->imgs.floor.img || !game->imgs.player.img
		|| !game->imgs.collect.img || !game->imgs.exit.img
		|| !game->imgs.enemy.img)
	{
		if (!game->imgs.wall.img)// debug 
			ft_printf("Error: Failed to load WALL\n");//ERASE
		if (!game->imgs.floor.img)//debug
			ft_printf("Error: Failed to load FLOOR\n");//ERASE
		if (!game->imgs.player.img)//debug
			ft_printf("Error: Failed to load PLAYER\n");//ERASE
		if (!game->imgs.collect.img)//debug
			ft_printf("Error: Failed to load ITEM\n");//ERASE
		if (!game->imgs.exit.img)//debug
			ft_printf("Error: Failed to load EXIT\n");//ERASE
		if (!game->imgs.enemy.img)//debug
			ft_printf("Error: Failed to load ENEMY\n");//ERASE
		close_handler(game, "Failed to load one or more images");
		return ;
	}
}

void	my_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game || !game->mlx)
	{
		close_handler(game, "MLX initialization failed");
		return ;
	}
	init_positions(game);
	game->win = mlx_new_window(game->mlx, game->size.x * TILE_SIZE,
			game->size.y * TILE_SIZE, "So_Long");
	if (!game->win)
	{
		close_handler(game, "Window creation failed");
		return ;
	}
	load_game_images(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, handle_keypress, game);
	
    // Add expose hook to handle window redraw events
	mlx_expose_hook(game->win, render_frame, game);//flickering issue
	
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
}
/*
	mlx_hook(game->win, 17, 0, close_window, game); // X button close
	mlx_key_hook(game->win, handle_keypress, game); // Keyboard hooks
	mlx_loop_hook(game->mlx, render_frame, game);   // Game loop
*/
/*
void	load_game_images(t_game *game)
{
	int	size_x;
	int	size_y;

	game->imgs.wall.img = mlx_xpm_file_to_image(game->mlx, 
	"imgs/wall.xpm", &size_x, &size_y);
	game->imgs.floor.img = mlx_xpm_file_to_image(game->mlx, 
	"imgs/BG_6.xpm", &size_x, &size_y);
	game->imgs.player.img = mlx_xpm_file_to_image(game->mlx, 
	"imgs/player1.xpm", &size_x, &size_y);
	game->imgs.collect.img = mlx_xpm_file_to_image(game->mlx, 
	"imgs/BG_2.xpm", &size_x, &size_y);
	game->imgs.exit.img = mlx_xpm_file_to_image(game->mlx, 
	"imgs/BG_3.xpm", &size_x, &size_y);
	game->imgs.enemy.img = mlx_xpm_file_to_image(game->mlx, 
	"textures/BG_5.xpm", &size_x, &size_y);
	if (!game->imgs.wall.img || !game->imgs.floor.img 
		|| !game->imgs.player.img 
		|| !game->imgs.collect.img || !game->imgs.exit.img 
		|| !game->imgs.enemy.img )
	{
		close_handler(game, "Failed to load one or more images");
		return ;
	}
	game->imgs.wall.addr = mlx_get_data_addr(game->imgs.wall.img,
					&game->imgs.wall.bppix,
					&game->imgs.wall.line_len, &game->imgs.wall.endian);
	game->imgs.floor.addr = mlx_get_data_addr(game->imgs.floor.img, 
	&game->imgs.floor.bppix,
								&game->imgs.floor.line_len, 
								&game->imgs.floor.endian);
	game->imgs.player.addr = mlx_get_data_addr(game->imgs.player.img, 
	&game->imgs.player.bppix,
								&game->imgs.player.line_len, 
								&game->imgs.player.endian);
	game->imgs.collect.addr = mlx_get_data_addr(game->imgs.collect.img, 
	&game->imgs.collect.bppix,
								&game->imgs.collect.line_len, 
								&game->imgs.collect.endian);
	game->imgs.exit.addr = mlx_get_data_addr(game->imgs.exit.img, 
	&game->imgs.exit.bppix,
				&game->imgs.exit.line_len, &game->imgs.exit.endian);
	game->imgs.enemy.addr = mlx_get_data_addr(game->imgs.enemy.img, 
	&game->imgs.enemy.bppix,
								&game->imgs.enemy.line_len, 
								&game->imgs.enemy.endian);

}
*/
/* inside if
		if (!game->imgs.wall.img)// debug 
			ft_printf("Error: Failed to load textures/wall.xpm\n");
		if (!game->imgs.floor.img)//debug
			ft_printf("Error: Failed to load textures/BG_6.xpm\n");
		if (!game->imgs.player.img)//debug
			ft_printf("Error: Failed to load textures/player1.xpm\n");
		if (!game->imgs.collect.img)//debug
			ft_printf("Error: Failed to load textures/item.xpm\n");
		if (!game->imgs.exit.img)//debug
			ft_printf("Error: Failed to load textures/exit.xpm\n");
		if (!game->imgs.enemy.img)//debug
			ft_printf("Error: Failed to load textures/enemy.xpm\n");
*/
