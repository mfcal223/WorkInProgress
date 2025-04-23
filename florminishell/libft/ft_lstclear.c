/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:02:40 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 08:07:00 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && del)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = temp;
		}
		*lst = NULL;
	}
}

/*#include <stdio.h>

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

	ft_lstclear(&element1, del);

	if(!element1)
		printf("List cleared\n");
	else
		printf("ft_lstclear failed\n");
	return (0);
}*/
