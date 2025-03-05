/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:28:54 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 16:37:01 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (!new)
		return ;
	new -> next = *list;
	*list = new;
}
/*
#include <stdio.h>
int     main()
{
        t_list  *frontlst = ft_lstnew("Hello");
	t_list	*new_element = ft_lstnew("42");

	printf("Listed elements: \n%s\n%s\n", (char *)frontlst->content,
		(char *)new_element->content);

	ft_lstadd_front (&frontlst, new_element);
	printf("New first element: %s\n", (char *)frontlst->content);

       	free(frontlst->next);
	free(frontlst);
        return (0);
}*/
