#include "so_long.h"

char	**duplicate_map(t_game *game) // = create duplicate = array_str (ft_map_status) to check other things
{
	t_map	*tmp;
	char	**duplicate;
	int i;

	i = 0;
	tmp = game->map;
	duplicate = malloc(sizeof(char *) * (game->size.y + 1));
	// allocate for all n elements as lines + 1 for null
	if (!duplicate)
		return (NULL);
	while (game->map)
	{
		duplicate[i] = ft_strdup(game->map->map);
		if (!duplicate[i])
		{
			free_duplicate(duplicate, i);
			return (NULL);
		}
		i++;
		game->map = game->map->next;
	}
	game->map = tmp;
	duplicate[i] = NULL;
	return (duplicate);
}

int	map_x_width(t_map *width) // = num of columns (ft_map_x) = num of char
{
	int x;

	x = 0;
	while (width->map[x] != '\n')
		x++;
	return (x);
}

int	map_y_heigth(t_map *height) // = num of lines (ft_map_y) = num of nodes
{
	int y;

	y = 0;
	while (height)
	{
		y++;
		height = height->next;
	}
	return (y);
}

t_map	*create_map_array(t_game *game) // ft_map_init
{
	char *line;
	int fd;

	fd = open(game->path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error initializing map.\n");
		return (NULL);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		create_array(game, line); // checks no empty lines in file
		line = get_next_line(fd);
	}
	close(fd);
	return (game->map);//map = linked list con nodos = c/linea
}

int	build_map(t_game **game)
{
	t_game	*temp;

	temp = *game;
	temp->map = create_map_array(temp);
	if (!temp->map)
	{
		free(temp);
		return (1);
	}
	temp->size.x = map_x_width(temp->map);
	temp->size.y = map_y_heigth(temp->map);
	temp->array_map = duplicate_map(temp);
	if (!temp->array_map)
	{
		ft_free_all(temp, 2);
		return (1);
	}
	temp->array_ff = duplicate_map(temp);
	if (!temp->array_ff)
	{
		ft_free_all(temp, 1);
		return (1);
	}
	*game = temp;
	return (0);
}

/* they read a map file, check its content, compute its dimensions,
 and create duplicate representations of the map for later use (for
 instance, for gameplay logic or pathfinding). */