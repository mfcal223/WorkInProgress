/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:39:45 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/26 14:39:46 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* compare quantity of elementes counted in the map and counted by 
flood fill (which are reachables)*/
int	ft_check_obj(t_cell checked, t_cell objects)
{
	if (checked.player != objects.player)
		return (1);
	if (checked.item != objects.item)
		return (1);
	if (checked.exit != objects.exit)
		return (1);
	return (0);
}

/* checks minimun quantities are fullfilled */
int	ft_check_obj_nbr(t_cell objects)
{
	if (objects.player != 1)
		ft_printf("Error: there should be 1 player.\n");
	if (objects.item < 1)
		ft_printf("Error: there should be min 1 collectible.\n");
	if (objects.exit != 1)
		ft_printf("Error: there should be 1 exit.\n");
	return (0);
}

/* checks it is a rectangle */
int	ft_check_form(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->array_map[j][i] != '\n' && game->array_map[j][i] != '\0')
		{
			if (game->array_map[j][i] != FLOOR && game->array_map[j][i] != WALL
				&& game->array_map[j][i] != PJ && game->array_map[j][i] != 'C'
				&& game->array_map[j][i] != EXIT)
				return (1);
			i++;
		}
		if (i != game->size.x)
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_borders(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->size.y)
	{
		i = 0;
		while (game->array_map[j][i] != '\n' && game->array_map[j][i] != '\0')
		{
			if (j == 0 && game->array_map[j][i] != WALL)
				return (1);
			if (j == game->size.y - 1 && game->array_map[j][i] != WALL)
				return (1);
			if (j != 0 && (i == 0 || i == game->size.x - 1)
				&& game->array_map[j][i] != WALL)
				return (1);
			if (j != game->size.y - 1 && (i == 0 || i == game->size.x - 1)
				&& game->array_map[j][i] != WALL)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
/*j = rows / i = columns */
/* cambiar nombre a map_check */
int	ft_check_failed(t_game *game, t_cell objects)
{
	int x;

	x = 0;
	if (ft_check_obj_nbr(objects) == 1)
		x = 1;
	if (ft_check_obj(game->cell, objects) == 1)
		x = 1;
	if (ft_check_form(game) == 1)
		x = 1;
	if (ft_check_borders(game) == 1)
		x = 1;
	if (x == 1)
	{
		ft_printf("Map check failed. Try other map file.\n");
		return (1);
	}
	return (0);
}

/* CHECK_FORM version 1
int	ft_check_form(t_game *game)
{
	int	i;
	int	j;
	int	l_size;

	j = 0;
	l_size = 0;
	while (game->array_map[j][l_size] != '\n')
		l_size++;
	while (j < game->size.y)
	{
		i = 0;
		while (game->array_map[j][i] != '\n' && game->array_map[j][i] != '\0')
		{
			if (game->array_map[j][i] != FLOOR && game->array_map[j][i] != WALL
				&& game->array_map[j][i] != PJ && game->array_map[j][i] != 'C'
				&& game->array_map[j][i] != EXIT)
				return (1);
			i++;
		}
		if (l_size != i)
			return (1);
		j++;
	}
	return (0);
}*/