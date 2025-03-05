#include "so_long.h"

void    find_player_position(char **map, int *x, int *y)
{
    *y = 0;
    while (map[*y])
    {
        *x = 0;
        while (map[*y][*x])
        {
            if (map[*y][*x] == PJ)
                return;
            (*x)++;
        }
        (*y)++;
    }
}

void    find_enemy_position(char **map, int *x, int *y, int index)
{
    int count;

    count = 0;
    *y = 0;
    while (map[*y])
    {
        *x = 0;
        while (map[*y][*x])
        {
            if (map[*y][*x] == ENEMY)
            {
                if (count == index)
                    return;
                count++;
            }
            (*x)++;
        }
        (*y)++;
    }
}

void init_positions(t_game *game)
{
    int i;
    int x;
    int y;

    // Initialize player position
    find_player_position(game->array_map, &x, &y);
    game->player_pos.pos.x = x;
    game->player_pos.pos.y = y;
    game->player_pos.win_pos.x = x * TILE_SIZE;
    game->player_pos.win_pos.y = y * TILE_SIZE;
    game->player_pos.moving = 0;

    // Initialize enemy positions
    game->enemy_pos = malloc(sizeof(t_posit) * game->enemy_count);
    if (!game->enemy_pos)
        close_handler(game, "Failed to allocate enemy positions");

    i = 0;
    while (i < game->enemy_count)
    {
        find_enemy_position(game->array_map, &x, &y, i);
        game->enemy_pos[i].pos.x = x;
        game->enemy_pos[i].pos.y = y;
        game->enemy_pos[i].win_pos.x = x * TILE_SIZE;
        game->enemy_pos[i].win_pos.y = y * TILE_SIZE;
        game->enemy_pos[i].moving = 0;
        i++;
    }
}

/*
void    init_player_position(t_game *game)
{
    int x;
    int y;

    find_player_position(game->array_map, &x, &y);
    
    // Initialize both grid and window positions to the same starting point
    game->player_pos.pos.x = x;
    game->player_pos.pos.y = y;
    game->player_pos.win_pos.x = x * TILE_SIZE;
    game->player_pos.win_pos.y = y * TILE_SIZE;
    game->player_pos.moving = 0;
}

void    init_enemies(t_game *game)
{
    count_enemies(game);
    if (game->enemy_count == 0)
    {
        game->enemy_pos = NULL;
        return;
    }
    game->enemy_pos = malloc(sizeof(t_posit) * game->enemy_count);
    if (!game->enemy_pos)
        return (close_handler(game, "failed to init enemies\n"));
    store_enemies(game);
}
*/