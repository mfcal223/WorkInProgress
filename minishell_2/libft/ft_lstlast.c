/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:58:08 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 16:10:09 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*j;

	j = lst;
	if (!j)
		return (NULL);
	while (j->next)
		j = j->next;
	return (j);
}

/*#include <stdio.h>
#include <stdlib.h>

int     main()
{
        t_list  *lst = ft_lstnew("Hello");
	t_list	*new_element = ft_lstnew("42");

	ft_lstadd_front(&lst, new_element);

	printf("Listed elements: \n%s\n%s\n", (char *)lst->content,
		(char *)lst->next->content);

	t_list *last_element = ft_lstlast (lst);
	printf("Last Listed element: %s\n", (char *)last_element->content);

	t_list *temp;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
        return (0);
}*/
