/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:45:44 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/25 10:22:32 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/*#include <stdio.h>
#include <stdlib.h>

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
