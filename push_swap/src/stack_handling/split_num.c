/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:49:35 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/14 14:38:09 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	*convert_to_numbers(char **array_words, int count)
{
	int	*array_number;
	int	i;

	array_number = (int *)malloc(sizeof(int) * count);
	if (!array_number)
	{
		free_split(array_words);
		return (NULL);
	}
	i = 0;
	while (i < count)
	{
		if (!is_valid_integer(array_words[i]))
		{
			free_split(array_words);
			free(array_number);
			return (NULL);
		}
		array_number[i] = ft_atoi(array_words[i]);
		i++;
	}
	free_split(array_words);
	return (array_number);
}

int	*split_num(char *string, int *count)
{
	char	**array_words;
	int		*array_number;
	int		i;

	array_words = ft_split(string, ' ');
	if (!array_words)
		return (NULL);
	i = 0;
	while (array_words[i])
		i++;
	*count = i;
	array_number = convert_to_numbers(array_words, i);
	return (array_number);
}
