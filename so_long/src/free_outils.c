/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:15:07 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/26 14:20:53 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_duplicate(char **duplicate, int len)
{
	int	i;

	i = 0;
	while (i <= len - 1)
	{
		free(duplicate[i]);//free each string
		duplicate[i] = NULL;
		i++;
	}
	free(duplicate); //free the container
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

void	ft_free_all(t_game *game, int error)
{
	if (error == 2)
	{
		if (game->array_map)
			free_duplicate(game->array_map, game->size.y);
		free_list(&game->map);
		free(game);
	}
	else if (error == 1)
	{
		if (game->array_map)
			free_duplicate(game->array_map, game->size.y);
		if (game->array_ff)
			free_duplicate(game->array_ff, game->size.y);
		free_list(&game->map);
		free(game);
	}
	else if (error == 0)
	{
		free_duplicate(game->array_map, game->size.y);
		free_duplicate(game->array_ff, game->size.y);
		free_list(&game->map);
		free(game);
	}
}

/* void	ft_free_all(t_game *game, int error)//ver si no borrar lo del int error
{
	(void)error;  // If error code is not used for different cleanups, you can ignore it.
	if (game->array_map)
		free_duplicate(game->array_map, game->size.y);
	if (game->array_ff)
		free_duplicate(game->array_ff, game->size.y);
	free_list(&game->map);
	// Free any additional resources here (e.g., images, texts, mlx stuff)
	free(game);
}*/ /* esta version esta dificil manejar el free de lo demas como una opcion */

/*
void	ft_free_all(t_game *game, int error)
{
		if (error == 2)// if duplicate for array_map fails (array_ff no existe)
	{
		free_duplicate(game->array_map, game->size.y);
		free_list(&game->map);
		free(game);
	}
	if (error == 1)// duplicate for array_ff fallo, pero array_map fue exitoso
	{
		free_duplicate(game->array_ff, game->size.y);
		free_list(&game->map);
		free(game);
	}
	if (error == 0)
	{
		free_duplicate(game->array_map, game->size.y);
		free_duplicate(game->array_ff, game->size.y);
		free_list(&game->map);
		//ft_free_txt(&game); //for future implementation
		//ft_free_img(&game); //for future implementation
		//mlx_terminate(game->mlx); //for future implementation
		free(game);
	}
}*/
/*
void	ft_free_txt(t_game **game)
{
	mlx_delete_texture((*game)->txts.ocean);
	(*game)->txts.ocean = NULL;
	mlx_delete_texture((*game)->txts.wall);
	(*game)->txts.wall = NULL;
	mlx_delete_texture((*game)->txts.collec);
	(*game)->txts.collec = NULL;
	mlx_delete_texture((*game)->txts.exit_c);
	(*game)->txts.exit_c = NULL;
	mlx_delete_texture((*game)->txts.exit_o);
	(*game)->txts.exit_o = NULL;
	mlx_delete_texture((*game)->txts.player);
	(*game)->txts.player = NULL;
	mlx_delete_texture((*game)->txts.player_u);
	(*game)->txts.player_u = NULL;
	mlx_delete_texture((*game)->txts.player_d);
	(*game)->txts.player_d = NULL;
	mlx_delete_texture((*game)->txts.player_l);
	(*game)->txts.player_l = NULL;
	mlx_delete_texture((*game)->txts.player_r);
	(*game)->txts.player_r = NULL;
	mlx_delete_texture((*game)->txts.shark);
	(*game)->txts.shark = NULL;
}

void	ft_free_img(t_game **game)
{
	mlx_delete_image((*game)->mlx, (*game)->imgs.ocean);
	(*game)->imgs.ocean = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.wall);
	(*game)->imgs.wall = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.collec);
	(*game)->imgs.collec = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.exit_c);
	(*game)->imgs.exit_c = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.exit_o);
	(*game)->imgs.exit_o = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.player);
	(*game)->imgs.player = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.player_u);
	(*game)->imgs.player_u = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.player_d);
	(*game)->imgs.player_d = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.player_l);
	(*game)->imgs.player_l = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.player_r);
	(*game)->imgs.player_r = NULL;
	mlx_delete_image((*game)->mlx, (*game)->imgs.shark);
	(*game)->imgs.shark = NULL;
}
*/


// char	**free_matrix(char **matrix, int cont)
// {
// 	int	i;

// 	i = 0;
// 	while (i < cont)
// 	{
// 		free(matrix[i]);
// 		matrix[i] = NULL;
// 		i++;
// 	}
// 	free(matrix);
// 	matrix = NULL;
// 	return (matrix);
// }
