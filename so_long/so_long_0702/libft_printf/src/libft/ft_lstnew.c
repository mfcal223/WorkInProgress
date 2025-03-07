/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:01:23 by mcalciat          #+#    #+#             */
/*   Updated: 2024/10/29 15:05:35 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node -> content = content;
	new_node -> next = (NULL);
	return (new_node);
}
/*
#include <stdio.h>
int	main()
{
	char	*content = "aloha buen dia";
	t_list	*new_element = ft_lstnew(content);

	if (new_element) //si la creacion fue exitosa (NO es null)
	{
		printf("New element added.\nContent: %s\n",
			(char *)new_element->content);
		printf("Next: %p\n", (void *)new_element->next);
	}
	else //si no se creó, algo falló
		printf("Error. New element failed.\n");
	free(new_element);
	return (0);
}*/
