#include "so_long.h"

t_map	*add_line(char *line) /* duplicates the line and stores in a list node*/
{
	t_map	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->map = ft_strdup(line);
	if (!new->map)
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

void	append_line(t_game *game, t_map *new)/* appends new node to map list */
{
	t_map	*last;

	last = game->map;
	if (!last)
		game->map = new;
	else
	{
		while (last->next)
			last = last->next;//finds last node
		last->next = new;//appends node to the list
	}
}

void	create_array(t_game *game, char *line)
{
	t_map	*new;

	if (line[0] == '\n')
	{
		ft_printf("Map error: found empty line.\n");
		free(line);//frees memory allocated by gnl
		exit(1);
	}
	new = add_line(line);
	append_line(game, new);
	free(line);//frees memory allocated by gnl
}

/* MAP VALIDATION */
int	check_extension(char *map)
{
	int len;

	if (!map)
		return (1);
	len = ft_strlen(map);
	if (len < 5 || map[0] == '.')
		return (1);
	if (map[len - 4] == '.' && map[len - 3] == 'b' && map[len - 2] == 'e'
		&& map[len - 1] == 'r')
		return (0);
	return (1);
}