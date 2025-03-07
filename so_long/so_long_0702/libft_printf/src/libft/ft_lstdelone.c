/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:04:32 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/30 11:06:44 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	else
	{
		del(lst -> content);
		free(lst);
	}
	return ;
}
/*#include <stdio.h>
void	del(void *content)
{
	free(content);
}

int     main()
{
	t_list *element1 = ft_lstnew(ft_strdup("Hello"));
	t_list *element2 = ft_lstnew(ft_strdup("42"));
	t_list *element3 = ft_lstnew(ft_strdup("hola"));

	element1 -> next = element2;
	element2 -> next = element3;
	element3 -> next = (NULL);
	
	printf("Listed elements: \n%s\n%s\n%s\n", (char *)element1->content,
		(char *)element2->content, (char *)element3->content);

	ft_lstdelone(element1, del); //borro el nodo1
	element1 = element2; //actualizo la posicion de los otros nodos
	element2 = element3;

	printf("Listed elements after ft_lstdelone: \n%s\n%s\n",
		(char *)element1->content, (char *)element2->content);

	ft_lstdelone(element1, del);
	ft_lstdelone(element2, del);
	return (0);
}*/
