#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_printf/inc/ft_printf.h"
# include "../libft_printf/inc/libft.h"
# include <mlx.h>    /* This is the correct way when using -I flag */
# include <stddef.h> // Needed for NULL
# include <stdlib.h>
# include <unistd.h>

//#define MAP_FOLDER "maps/"
# define W_WIDTH 800
# define W_HEIGHT 600

/* struc used in initial window handling */
/*typedef struct s_image
{
	void	*img;
	char	*addr;			//pixel ptr (to the 1st pixel)
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;*/
/* // MY ORIGINAL STRUC
typedef struct s_game
{
	void    *mlx;	//ptr return by mlx_init
	void    *win;	// ptr to the window
	t_image			pic;
}					t_game;
*/

/* structure for the game*/
typedef struct s_map // linked list to store the map
{
	char			*map;
	struct s_map	*next;
}					t_map;

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_pixel
{
	void	*img;  // Image pointer (MiniLibX)
	char	*addr; // Pixel data pointer
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_pixel;

typedef struct s_imgs
{
	t_pixel wall;    // Image for walls ('1')
	t_pixel floor;   // Image for empty spaces ('0')
	t_pixel player;  // Image for player ('P')
	t_pixel collect; // Image for collectibles ('C')
	t_pixel exit;    // Image for exit ('E')
}					t_imgs;

typedef struct s_game
{
	void	*mlx;			// MiniLibX instance
	void	*win;			// Window instance
	char	*path;			// Path to the map file
	t_map	*map;			// Linked list storing the map
	char	**array_map;	// 2D array for map representation
	char	**array_ff;		// 2D array for flood-fill validation
	t_coord	size;     		// Map size (width & height)
	t_coord	player;   		// Player position (x, y)
	int		moves;			// Number of player moves
	int		items;			// Number of collectibles
	//int	flag;			// to use to allowed using the exit in the map
	t_imgs	imgs;
}			t_game;

/* MAP CHECK */
int		check_extension(char *map);

/* WINDOW ADMIN */
int		close_window(t_game *game);
void	my_mlx_pixel_put(t_pixel *img, int x, int y, int color);
int		handle_keypress(int keycode, t_game *game);
int		window_init(char *map);

#endif

/*
#ifndef SO_LONG_H           // If the header file has not been included.
# define SO_LONG_H          // Define the header file.

# include "../MLX42/include/MLX42/MLX42.h"  // MLX42 library.
# include "../ft_printf/ft_printf.h"        // Custom printf function.
# include "../libft/libft.h"                // Custom library functions.
# include "./MLX42/MLX42.h"                 // MLX42 library.
# include <fcntl.h>         // File control options. Used for open().
# include <stdarg.h>        // VA. To use va_list, va_start, va_arg, va_end.
# include <stdio.h>         // Standard input/output definitions.
# include <stdlib.h>        // General utilities.
# include <unistd.h>        // Used for read() and close().

// *** Name of the game. ***

# define NAME "so_long"     // Name of the executable.
# define TITRE "So Long"    // Title of the window.

# define TILE_SIZE 32       // Size of the tiles in pixels.
# define IMG_SIZE 48        // Size of the images in pixels.

// *** Window size. ***

# define WIDTH 1920         // Width of the window.
# define HEIGHT 1080        // Height of the window.

# define TRUE 1             // Boolean true.
# define FALSE 0            // Boolean false.
# define BOOL 				 // Boolean type. Value can be TRUE or FALSE.

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
# define SLOW_BLINK "\033[5m"   	// Slow blink for the terminal.

// *** Map elements. ***

# define PLAYER 'P'     // Player character.
# define ENEMY 'X'      // Enemy character.
# define WALL '1'       // Wall character.
# define FLOOR '0'      // Floor character.
# define COLLECT 'C'    // Collectible character.
# define EXIT 'E'       // Exit character.

// *** Error messages. ***

# define ERR_FILE "Invalid name of the map, must be a *.ber file\n"
# define ERR_CHAR "The map contains invalid characters.\n"
# define ERR_MLX "Failed MLX initiation.\n"
# define ERR_MAP "The map was not found or cannot be opened.\n"
# define ERR_INIT "Usage: ./so_long [map.ber].\n"
# define ERR_PLAYER "The map must contain one player (ship), and only one.\n"
# define ERR_COLLEC "The map must contain at least one collectible.\n"
# define ERR_EXIT "The map must contain one exit, and only one.\n"
# define ERR_FORMAT "The map is not rectangular.\n"
# define ERR_BORDER "The map must be surrounded by walls.\n"
# define ERR_LINE "Empty line has been detected in the file.\n"
# define ERR_GENERAL "Map or objects failed.\n"

// *** Return values. ***

# define ERROR -1       // Error return value. Used for error handling.
# define FAILURE 1      // Failure return value. Used for error handling.
# define SUCCESS 0      // Success... 0 is the default return value.

// *** Keycodes for the game. ***

# define LEFT 65361        // ASCII value for the left arrow key.
# define RIGHT 65363       // ASCII value for the right arrow key.
# define DOWN 65364        // ASCII value for the down arrow key.
# define UP 65362          // ASCII value for the up arrow key.

# define ESC 65307         // ASCII value for the 'esc' key.

// *** Paths to graphic imgs. ***

// # define IBEGIN "imgs/begin.xpm"       //Image of the beginning.
// # define IPLAYER "imgs/player.xpm"     //Image of the player.
// # define IENEMY "imgs/enemy.xpm"       //Image of the enemy.
// # define IWALL "imgs/wall.xpm"         //Image of the wall.
// # define IFLOOR "imgs/floor.xpm"       //Image of the floor.
// # define ICOLLECT "imgs/collect.xpm"   //Image of the collectible.
// # define IEXIT "imgs/exit.xpm"         //Image of the exit.

// *** Structure for the textures. ***

typedef struct s_txts
{
	mlx_texture_t	*ocean;
	mlx_texture_t	*wall;
	mlx_texture_t	*collec;
	mlx_texture_t	*exit_c;
	mlx_texture_t	*exit_o;
	mlx_texture_t	*ship;
	mlx_texture_t	*ship_u;
	mlx_texture_t	*ship_d;
	mlx_texture_t	*ship_l;
	mlx_texture_t	*ship_r;
	mlx_texture_t	*shark;
	//mlx_texture_t   *shark_u;
	//mlx_texture_t   *shark_d;
	// mlx_texture_t   *shark_l;
	// mlx_texture_t   *shark_r;
}					t_txts;

//The textures are created to store the texture of the game. The textures
//are used to give the visual aspect of the objects in the game.

// *** Structure for the images. ***

typedef struct s_images
{
	mlx_image_t		*ocean;
	mlx_image_t		*wall;
	mlx_image_t		*collec;
	mlx_image_t		*exit_c;
	mlx_image_t		*exit_o;
	mlx_image_t		*ship;
	mlx_image_t		*ship_u;
	mlx_image_t		*ship_d;
	mlx_image_t		*ship_l;
	mlx_image_t		*ship_r;
	mlx_image_t		*shark;
	// mlx_image_t		*shark_u;
	// mlx_image_t		*shark_d;
	// mlx_image_t		*shark_l;
	// mlx_image_t		*shark_r;
}					t_images;

//The images are created to store the images of the game. The images are
//the visual objetcs that are displayed in the game.

// *** Structure for the map. ***

typedef struct s_map
{
	char			*map;
	struct s_map	*next;
}					t_map;

//The map is used to store the map of the game. *map store the information
//of the map. *next is used to store the next map. For example, if the player
//goes to the next level. It is not used in this game.

// *** Structure for the cells. ***

typedef struct s_cell
{
	int				ship;
	int				shark;
	int				ocean;
	int				wall;
	int				collec;
	int				exit;
}					t_cell;

//The cells are used to store the information of the cells of the game.
//For example, if the cell contains a ship, a wall...
//The values are set to 0 or 1 to indicate if the cell contains the object.

// *** Structure for the key codes. ***

typedef struct s_key_press
{
	int				key;
}					t_key_press;

//The key press is used to store the key pressed by the player.

// *** Structure for the position. ***

typedef struct s_coord
{
	int				x;
	int				y;
}					t_coord;

//The coord structure is used to store the position of the objects in the game.

// *** Structure for the game. ***

typedef struct s_init
{
	mlx_t			*mlx;			// Connection to the graphic display.
	t_txts			txts;			// Textures of the game.
	t_images		imgs;			// Images of the game.
	t_cell			cell;			// Object of the game.
	t_map			*map;			// Map of the game.
	t_coord			ship;			// Position of the player.
	t_coord			shark;			// Position of the enemy.
	t_coord			size;			// Size in pixels of the window.
	char			**status_a;		// Matrix of the map.
	char			**status_b;		// Matrix of the map.
	char			*path;			// Path to the map.
	int				moves;			// Number of moves.
	int				counter;		// Number of collectibles.
	int				collec;			// Number of collectibles.
	int				c;			// Collectibles collected.
	int				flag;			// 0 = game, 1 = win, 2 = lose
	char			course;			// Direction of the player.
	bool			walking;		// Walking or not.
}					t_init;

//The game structure is used to store the information of the game.
//	*mlx is used to store the connection to the display.
//	textures is used to store the textures of the game.
//	images is used to store the images of the game.
//	cell is used to store the information of the cells of the game.
//	*map is used to store the map of the game.
//	ship is used to store the position of the ship, the player.
//	path is used to store the path of the map.
//	moves is used to store the number of moves of the player.
//	counter is used to store the number of collectibles.
//	collec is used to store the number of collectibles.
//	flag is used to store the flag of the game. 0 = game, 1 = win, 2 = lose.
//	course is used to store the direction of the player.
//	walking is used to store if the player is walking or not.
*/