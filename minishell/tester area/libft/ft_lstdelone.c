/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:15:48 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 08:09:06 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
	return ;
}

/*#include <stdio.h>
#include <stdlib.h>
void	del(void *content)
{
	free(content);
}

int     main()
{
	t_list  *element1 = ft_lstnew("Hello");
	t_list	*element2 = ft_lstnew("42");
	t_list	*element3 = ft_lstnew("!!!");

	element1 -> next = element2;
	element2 -> next = element3;
	element3 -> next = (NULL);
	
	printf("Listed elements: \n%s\n%s\n%s\n", (char *)element1->content,
		(char *)element2->content, (char *)element3->content);

	ft_lstdelone(element1, del);
	element1 = element2;
	element2 = element3;

	printf("Listed elements after ft_lstdelone: \n%s\n%s\n",
		(char *)element1->content, (char *)element2->content);

	ft_lstdelone(element1, del);
	ft_lstdelone(element2, del);
	return (0);
}*/
