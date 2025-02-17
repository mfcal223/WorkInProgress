/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:56:31 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/17 10:44:48 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty_or_null(char *string)
{
	if (!string || *string == '\0')
		return (1);
	return (0);
}

int	has_invalid_chars(char *string)
{
	int	i;

	i = 0;
	if (string[i] == '+' || string[i] == '-')
		i++;
	if (string[i] == '\0')
		return (1);
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_out_of_range(char *string)
{
	long	num;

	num = ft_atol(string);
	if (num > INT_MAX || num < INT_MIN)
	{
		return (1);
	}
	return (0);
}

int	is_valid_integer(char *string)
{
	if (is_empty_or_null(string) || has_invalid_chars(string))
	{
		display_error();
		return (0);
	}
	if (is_out_of_range(string))
	{
		display_error();
		return (0);
	}
	return (1);
}

int	check_duplicates(int *array_number, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (array_number[i] == array_number[j])
			{
				display_error();
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
