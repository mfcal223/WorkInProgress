/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:09:23 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/05 14:50:17 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_printf/inc/ft_printf.h"
# include "../libft_printf/inc/get_next_line.h"
# include "../libft_printf/inc/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>  // for open() and close()
# include <mlx.h>    /* This is the correct way when using -I flag */
# include <stddef.h> // Needed for NULL
# include <stdlib.h>
# include <unistd.h>

/* TILE / CELL WIDTH / HEIGTH size */
# define TILE_SIZE 64

/* Map elements. */
# define WALL '1'
# define FLOOR '0'
# define PJ 'P'
# define ITEM 'C'
# define EXIT 'E'
# define ENEMY 'X'

// *** Keycodes for the game. ***

# define KEY_ESC 65307		// 'esc' key.
# define KEY_W 119			// 'w' key
# define KEY_A 97			// 'a' key
# define KEY_S 115			// 's' key
# define KEY_D 100			// 'd' key
# define KEY_UP 65362		// up arrow key.
# define KEY_DOWN 65364		// down arrow key.
# define KEY_LEFT 65361		// left arrow key.
# define KEY_RIGHT 65363	// right arrow key.

typedef struct s_coord
{
	int		x;
	int		y;
}			t_coord;

typedef struct s_posit 
{
    t_coord	pos;			// Grid position (like 1,1)
    t_coord	win_pos;		// Actual pixel position on screen (like 32,32)
    int		moving;			// Are we currently moving between tiles?
}			t_posit;

typedef struct s_cell
{
	int	player;
	int	enemy;
	int	floor;
	int	wall;
	int	item;
	int	exit;
}		t_cell;

/* structure for the game*/
typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}					t_map;

typedef struct s_pixel
{
	void	*img;	// Image pointer (MiniLibX)
	char	*addr; // Pixel data pointer
	int		bppix;
	int		line_len;
	int		endian;
}			t_pixel;

typedef struct s_imgs
{
	t_pixel	wall;		// Image for walls ('1')
	t_pixel	floor;		// Image for empty spaces ('0')
	t_pixel	player;		// Image for player ('P')
	t_pixel	collect;	// Image for collectibles ('C')
	t_pixel	exit;		// Image for exit ('E')
	t_pixel	enemy;		// Image for enemy ('X')
}					t_imgs;

typedef struct s_game
{
	void	*mlx;			// MiniLibX instance
	void	*win;			// Window instance
	char	*path;			// Path to the map file
	t_map	*map;			// Linked list storing the map
	char	**array_map;	// 2D array for map representation (status_a)
	char	**array_ff;		// 2D array for flood-fill validation (status_b)
	t_coord	size;			// Map size (width & height)
	t_cell	cell;			// Content of a cell (coordenate?)
	int		moves;			// Number of player moves
	int		items;			// Number of collectibles
	int		flag;			// to use to allowed using the exit in the map
	int		enemy_count;	//total amount of enemies
	int		enemy_timer;	//control movement speed
	//t_coord	player;			// Player position (x, y)
	//t_coord	*enemies;		//track enemies position
	t_posit player_pos;   // For tracking player position
    t_posit *enemy_pos;   // Array for enemy positions
	t_imgs	imgs;
}			t_game;

void    find_player_position(char **map, int *x, int *y);
void    find_enemy_position(char **map, int *x, int *y, int index);
void    exit_error(t_game *game, char *message);

/* ENEMIES_MOVE */
//int			valid_move(char **array_map, int x, int y);
//int			select_enemy_direction(t_game *game, int i, int attempts);
void		choose_enemy_move(t_game *game, int *new_x, int *new_y, int i);
void		update_enemy_pos(t_game *game, int i, int new_x, int new_y);
void		move_enemies(t_game *game);

/* ENEMIES */

void		count_enemies(t_game *game);
void		store_enemies(t_game *game);
void		find_enemies(t_game *game);

/* FREE OUTILS */
void		free_single_image(void *mlx, t_pixel *img);
void		free_all_img(t_game **game);
void		free_duplicate(char **duplicate, int len);
void		free_list(t_map **stack);
int			close_window(t_game *game);

/* MAP CREATION 1 */
int			build_map(t_game **game);
int			dup_map_arrays(t_game *game);
int			init_map(t_game *game);

/* MAP CREATION 2*/
char		**duplicate_map(t_game *game);
int			map_x_width(t_map *width, t_game *game);
int			map_y_heigth(t_map *height, t_game *game);
t_map		*create_map(t_game *game);

/* MAP CREATION 3 */
t_map		*add_line(char *line);
void		append_line(t_game *game, t_map *new);
void		create_array(t_game *game, char *line);
int			check_extension(char *map);

/* MAP VALIDATION 1 */
t_cell		count_objects(t_map *map);
t_game		**cell_objects(t_game **game, char check);
t_game		**path_valid_ff(char **tab, t_coord size, t_coord curr,
				t_game **game);
t_game		*map_validation(t_game *game);
t_game		*find_player(t_game *game);

/* MAP VALIDATION 2 */
int			compare_counts(t_cell checked, t_cell objects);
int			check_min_count(t_cell objects);
int			ft_check_form(t_game *game);
int			ft_check_borders(t_game *game);
int			ft_check_failed(t_game *game, t_cell objects);

/* MLX_LOAD */
void		init_positions(t_game *game);
int			render_frame(t_game *game);
int			handle_keypress(int keycode, t_game *game);
void		load_game_images(t_game *game);
void		my_mlx_init(t_game *game);

/* MOVES */
void		update_player_position(t_game *game, int new_x, int new_y);
int			move_to_exit(t_game *game);
int			move_player(t_game *game, int dx, int dy);

/* RENDER */
void		render_map(t_game *game);
void		render_collectibles(t_game *game);
void		render_exit(t_game *game);
void		render_player(t_game *game);
void		render_enemies(t_game *game);

/* SO LONG */
int			close_handler(t_game *game, char *message);
t_game		*initialize_game(t_game *game);
int			game_start(char *map);

#endif
/*
// *** Colors for the terminal. ***
# define WHITE "\033[1;37m"     	// White color for the terminal.
# define RED "\033[1;31m"       	// Red color for the terminal.
# define GREEN "\033[1;32m"     	// Green color for the terminal.
# define YELLOW "\033[1;33m"    	// Yellow color for the terminal.
# define DARK_YELLOW "\033[1;93m" 	// Dark yellow color for the terminal.
# define BLUE "\033[1;34m"      	// Blue color for the terminal.
# define DARK_BLUE "\033[1;36m" 	// Dark blue color for the terminal.
# define MAGENTA "\033[1;35m"   	// Magenta color for the terminal.
# define PEACH "\033[1;91m"     	// Peach color for the terminal.
# define CYAN "\033[1;36m"      	// Cyan color for the terminal.
# define PINK "\033[1;95m"      	// Pink color for the terminal.
# define RESET "\033[0m"        	// Reset color for the terminal.
# define SLOW_BLINK "\033[5m"   	// Slow blink for the terminal.*/
