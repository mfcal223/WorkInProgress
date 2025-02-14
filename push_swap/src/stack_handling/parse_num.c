/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:36:54 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/06 09:37:00 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_num(int ac, char **av, int *count)
{
	int	*array_number;
	int	i;
	int	j;

	array_number = (int *)malloc(sizeof(int) * (ac - 1));
	if (!array_number)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (!is_valid_integer(av[i]))
		{
			free(array_number);
			return (NULL);
		}
		array_number[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	*count = j;
	return (array_number);
}
