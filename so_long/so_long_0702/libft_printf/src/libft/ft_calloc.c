/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:24:22 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/24 11:39:46 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;
	size_t			total;

	total = count * size;
	if (total != 0 && total / count != size)
		return (0);
	temp = malloc(total);
	if (!temp)
		return (0);
	i = 0;
	while (i < total)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
/*
#include <stdio.h>
int main() {
    int *arr1;
    int *arr2;
    char *str;
    size_t i;
    size_t n = 5;

    // Test case 1: Allocating memory for an array of 5 integers
    arr1 = (int *)ft_calloc(n, sizeof(int));
    printf("Test 1: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Test case 2: Allocating memory for an array of 10 integers
    arr2 = (int *)ft_calloc(10, sizeof(int));
    printf("Test 2: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Test case 3: Allocating memory for a string of 10 characters
    str = (char *)ft_calloc(10, sizeof(char));
    printf("Test 3: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");

    // Test case 4: Allocating zero elements
    char *zero_alloc = (char *)ft_calloc(0, sizeof(char));
    printf("Test 4: %p\n", (void *)zero_alloc);

    // Test case 5: Allocating zero size
    char *zero_size = (char *)ft_calloc(10, 0);
    printf("Test 5: %p\n", (void *)zero_size);

    // Test case 6: Null check for large alloc (might fail s/sys memory)
    size_t large_count = (size_t)-1;
    char *large_alloc = (char *)ft_calloc(large_count, sizeof(char));
    printf("Test 6: %p\n", (void *)large_alloc);

    free(arr1);
    free(arr2);
    free(str);
    free(zero_alloc);
    free(zero_size);
    free(large_alloc);

    return 0;
}*/
