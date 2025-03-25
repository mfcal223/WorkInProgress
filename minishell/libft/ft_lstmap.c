/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:22:00 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 08:47:55 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_element = ft_lstnew(new_content);
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}

/*#include <stdio.h>

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
}

void	del(void *content)
{
	free(content);
}

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
