/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:28:44 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 07:55:55 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (nptr[i] - '0') + (num * 10);
		i++;
	}
	return (num * sign);
}

/*#include <stdio.h>

int	main()
{
	const char	*n1;
	const char	*n2;
	const char	*n3;
	const char	*n4;
	const char	*n5;
	const char	*n6;
	const char	*n7;
	int	result;

	n1 = "42";
	result = ft_atoi(n1);
	printf("For n1 = %s, Atoi number = %d\n", n1, result);

	n2 = "-42";
	result = ft_atoi(n2);
	printf("For n2 = %s, Atoi number = %d\n", n2, result);

	n3 = "   123";
	result = ft_atoi(n3);
	printf("For n3 = %s, Atoi number = %d\n", n3, result);

	n4 = "   -4242abcdef";
	result = ft_atoi(n4);
	printf("For n4 = %s, Atoi number = %d\n", n4, result);

	n5 = "";
	result = ft_atoi(n5);
	printf("For n5 = %s, Atoi number = %d\n", n5, result);

	n6 = "  +-+---++789456hgfd";
	result = ft_atoi(n6);
	printf("For n6 = %s, Atoi number = %d\n", n6, result);

	n7 = "  +-++hello1234";
	result = ft_atoi(n7);
	printf("For n7 = %s, Atoi number = %d\n", n7, result);

	return 0;
}*/
