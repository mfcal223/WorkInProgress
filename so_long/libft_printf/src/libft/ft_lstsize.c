/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:50:04 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 17:03:02 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*copia;
	int		i;

	copia = lst;
	i = 0;
	while (copia)
	{
		copia = copia -> next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
    	// Caso 1: Lista vacía
	t_list	*list1 = NULL;
	printf("Size of list1: %d\n", ft_lstsize(list1));  // Espera 0
	// Caso 2: Lista con un solo nodo
	t_list	*list2 = ft_lstnew("Node 1");
	printf("Size of list2: %d\n", ft_lstsize(list2));  // Espera 1
	// Caso 3: Lista con varios nodos
	t_list	*list3 = ft_lstnew("Node 1");
	ft_lstadd_front(&list3, ft_lstnew("Node 2"));
	ft_lstadd_front(&list3, ft_lstnew("Node 3"));
	printf("Size of list3: %d\n", ft_lstsize(list3));  // Espera 3
	// Liberar memoria (opcional, pero recomendado)
	t_list	*temp;
	while (list2)
	{
		temp = list2;
		list2 = list2->next;
		free(temp);
	}
	while (list3)
	{
		temp = list3;
		list3 = list3->next;
		free(temp);
	}
	return (0);
}*/
