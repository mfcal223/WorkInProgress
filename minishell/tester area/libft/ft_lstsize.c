/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:25:58 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 16:08:24 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*j;
	int		i;

	i = 0;
	j = lst;
	while (j)
	{
		i++;
		j = j->next;
	}
	return (i);
}

/*#include <stdio.h>
#include <stdlib.h>

int     main()
{
        int	size;
	t_list  *lst = ft_lstnew("Hello");
	t_list	*new_element = ft_lstnew("42");

	ft_lstadd_front(&lst, new_element);

	printf("Listed elements: \n%s\n%s\n", (char *)lst->content,
		(char *)lst->next->content);
	
	size = ft_lstsize (lst);
	printf("List Size: %d\n", size);
       
	t_list *temp;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
        return (0);
}*/
