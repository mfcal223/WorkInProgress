#include "so_long.h"

/* MAP VALIDATION */
int check_extension(char *map)
{
    int len;

    if (!map)
        return (1);
    len = ft_strlen(map);
    if (len < 5 || map[0] == '.')
        return (1);
    if (map[len - 4] == '.' && map[len - 3] == 'b'
        && map[len - 2] == 'e' && map[len - 1] == 'r')
        return (0);
    return (1);
}