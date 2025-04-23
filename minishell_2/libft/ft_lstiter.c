/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:12:53 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 08:20:41 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*#include <stdio.h>
#include <stdlib.h>

void	to_upper (void *content)
{
	char	*str;

	str = (char *)content;
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int	main()
{
	t_list *element1 = ft_lstnew(ft_strdup("Hello"));
	t_list *element2 = ft_lstnew(ft_strdup("42"));
	t_list *element3 = ft_lstnew(ft_strdup("!!!"));

	element1->next = element2;
	element2->next = element3;
	element3->next = (NULL);

	printf("Listed elements: \n%s\n%s\n%s\n", (char *)element1->content,
			(char *)element2->content, (char *)element3->content);

	ft_lstiter(element1, to_upper);
	printf("After ft_lstiter + ft_toupper: \n%s\n%s\n%s\n",
		(char *)element1->content, (char *)element2->content,
		(char *)element3->content);
	return (0);
}*/
