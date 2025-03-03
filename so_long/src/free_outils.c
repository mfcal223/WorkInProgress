/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:15:07 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/03 14:47:37 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_single_image(void *mlx, t_pixel *img)
{
	if (img->img)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
}

void	free_all_img(t_game **game)
{
	void	*mlx;

	mlx = (*game)->mlx;
	free_single_image(mlx, &(*game)->imgs.floor);
	free_single_image(mlx, &(*game)->imgs.wall);
	free_single_image(mlx, &(*game)->imgs.player);
	free_single_image(mlx, &(*game)->imgs.collect);
	free_single_image(mlx, &(*game)->imgs.exit);
	free_single_image(mlx, &(*game)->imgs.enemy);
}

void	free_duplicate(char **duplicate, int len)
{
	int	i;

	i = 0;
	while (i <= len - 1)
	{
		free(duplicate[i]);
		duplicate[i] = NULL;
		i++;
	}
	free(duplicate);
}

void	free_list(t_map **list)
{
	t_map	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->map);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}

int	close_window(t_game *game)
{
	if (game->enemies)
		free(game->enemies);
	if (game->imgs.wall.img || game->imgs.floor.img
		|| game->imgs.player.img || game->imgs.collect.img
		|| game->imgs.exit.img)
	{
		free_all_img(&game);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->array_map)
		free_duplicate(game->array_map, game->size.y);
	if (game->array_ff)
		free_duplicate(game->array_ff, game->size.y);
	if (game->map)
		free_list(&game->map);
	free(game);
	exit(0);
	return (0);
}
