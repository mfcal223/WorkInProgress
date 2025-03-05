/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:25:27 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/30 12:32:43 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (0);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		else
		{
			ft_lstadd_back(&new_list, new_node);
			lst = lst->next;
		}
	}
	return (new_list);
}
/*
#include <stdio.h>

void	del(void *content)
{
	free(content);
}
void	*to_upper(void *content)
{
	char	*str;
	char	*new_str;
	int	i;

	str = (char *)content;
	new_str = ft_strdup(str);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = ft_toupper(new_str[i]);
		i++;
	}
	return (new_str);
}*/
/*
int	main()
{
	t_list *element1 = ft_lstnew(ft_strdup("Hello"));
	t_list *element2 = ft_lstnew(ft_strdup("42!"));
	t_list *new_list;
	t_list *temp;

	element1->next = element2;
	element2->next = (NULL);

	printf("Listed elements: \n%s\n%s\n", (char *)element1->content,
			(char *)element2->content);

	new_list = ft_lstmap(element1, to_upper, del);
	temp = new_list;
	printf("After ft_lstmap (to_upper / del): \n");
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&element1, del);
	ft_lstclear(&new_list, del);
	return (0);
}*/
