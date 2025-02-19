#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_printf/inc/ft_printf.h"
# include "../libft_printf/inc/libft.h"
# include <mlx.h> /* This is the correct way when using -I flag */
# include <stdlib.h>
# include <unistd.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars 
{
    void    *mlx;
    void    *win;
    t_data  pic;
}           t_vars;


#endif