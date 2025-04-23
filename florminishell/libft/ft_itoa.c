/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:15 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 10:58:15 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_digit_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n / 10 != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = ft_digit_count(n);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

/*#include <stdio.h>

int	main()
{
	int	n;
	char	*str;

	n = 123456789;
	str = ft_itoa(n);
	printf("Number: %d\nitoa: %s\n", n, str);
	free(str);

	n = -123456789;
	str = ft_itoa(n);
	printf("\nNumber: %d\nitoa: %s\n", n, str);
	free(str);

	n = 0;
	str = ft_itoa(n);
	printf("\nNumber: %d\nitoa: %s\n", n, str);
	free(str);

	n = -2147483648;
	str = ft_itoa(n);
	printf("\nNumber: %d\nitoa: %s\n", n, str);
	free(str);

	return (0);
}*/
