/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:56:38 by mcalciat          #+#    #+#             */
/*   Updated: 2025/03/12 16:35:00 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Function to check if a string is empty or contains other than digits */
int	is_number(char *str)
{
	int i;

	i = 0;
	if (!str[i]) // Check for empty string
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9') // Inlined ft_isdigit()
			return (0);
		i++;
	}
	return (1);
}

/* Check if a number is within valid ranges */
int	is_valid_number(long num, int index)
{
	if (num == -1)
	{
		printf("Error: Argument %d is out of valid range.\n", index);
		return (0);
	}
	if (index == 1 && (num < 1 || num > 200))
	{
		printf("Error: Number of philosophers must be between 1 and 200.\n");
		return (0);
	}
	if (index > 1 && num < 1)
	{
		printf("Error: Argument %d must be greater than 0.\n", index);
		return (0);
	}
	return (1);
}

/* Validate each argument */
int	check_numbers(int ac, char **av)
{
	int		i;
	long	num;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
		{
			printf("Error: Arg %d contains non-numeric characters.\n", i);
			return (0);
		}
		num = ft_atol(av[i]);
		if (!is_valid_number(num, i))
			return (0);
		i++;
	}
	return (1);
}

/* Main validation function */
int	validate_input(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong number of arguments (must be 5 or 6).\n");
		return (0);
	}
	if (!check_numbers(ac, av))
		return (0);
	return (1);
}
