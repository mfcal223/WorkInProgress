/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:39:50 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/30 11:45:09 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	else
	{
		while (*lst)
		{
			temp = (*lst)-> next;
			del((*lst)-> content);
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
	return ;
}
/*
#include <stdio.h>

void	del(void *content)
{
	free(content);
}

int	main()
{
	t_list	*element1 = ft_lstnew(ft_strdup("Hello"));
	t_list	*element2 = ft_lstnew(ft_strdup("42"));
	t_list	*element3 = ft_lstnew(ft_strdup("!!!"));

	element1->next = element2;
	element2->next = element3;
	element3->next = (NULL);

	printf("Listed elements: \n%s\n%s\n%s\n", (char *)element1->content,
			(char *)element2->content, (char *)element3->content);

	ft_lstclear(&element1, del); //que borre del primer elemento
	//de poner otro elemento hay que optimizar el main como en lstdelone
	//y que actualice los elementos

	if(!element1)
		printf("List cleared\n");
	else
		printf("ft_lstclear failed\n");
	return (0);
}*/
