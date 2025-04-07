/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:16:19 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/25 12:10:19 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
	return ;
}

/*#include <stdio.h>
#include <stdlib.h>

int     main()
{
	t_list	*lst = (NULL);
	t_list  *element1 = ft_lstnew("Hello");
	t_list	*element2 = ft_lstnew("42");
	t_list	*element3 = ft_lstnew("!!!");

	printf("Listed elements: \n%s\n%s\n%s\n", (char *)element1->content,
		(char *)element2->content, (char *)element3->content);

	ft_lstadd_back (&lst, element1);
	ft_lstadd_back (&lst, element2);
	ft_lstadd_back (&lst, element3);

	t_list *last_element = lst;
	while (last_element -> next)
	{
		last_element = last_element -> next;
	}
	printf("Last element: %s\n", (char *)last_element->content);

	t_list *temp;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	
	return (0);
}*/
