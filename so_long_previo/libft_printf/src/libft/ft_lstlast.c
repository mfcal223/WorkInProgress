/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:27:51 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 17:28:08 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (0);
	last = lst;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}
/*
#include <stdio.h>
int main()
{
	t_list *list = ft_lstnew("Nodo 1");
	ft_lstnew("Nodo 2");
	ft_lstnew("Nodo 3");
	t_list *second_node = ft_lstnew("Nodo 2");
	list->next = second_node;
	second_node->next = ft_lstnew("Nodo 3");

	t_list *last_node = ft_lstlast(list);

	if (last_node)
	{
		printf("El nodo final contiene: %s\n", (char *)last_node->content);
	}
	else
	{
		printf("La lista esta vacia.\n");
	}

	t_list *temp;
	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}*/
