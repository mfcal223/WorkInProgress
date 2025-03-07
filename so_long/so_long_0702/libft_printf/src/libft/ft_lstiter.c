/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:01:13 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/30 12:04:09 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/* 
// para test cc -Wall -Wextra -Werror 
//ft_lstiter.c ft_lstnew.c ft_strdup.c ft_strlen.c ft_toupper.c

#include <stdio.h>
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
	t_list *element2 = ft_lstnew(ft_strdup("Moien"));
	t_list *element3 = ft_lstnew(ft_strdup("aloha"));

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
