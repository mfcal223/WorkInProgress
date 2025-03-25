/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpiantan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:19:46 by mpiantan          #+#    #+#             */
/*   Updated: 2024/10/28 15:50:06 by mpiantan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = (t_list *) malloc (sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}

/*#include <stdio.h>

int	main()
{
	char	*content = "Hello 42";
	t_list	*new_element = ft_lstnew(content);

	if (new_element)
	{
		printf("New element added.\nContent: %s\n",
			(char *)new_element->content);
		printf("Next: %p\n", (void *)new_element->next);
	}
	else
		printf("Error. New element failed.\n");
	free(new_element);
	return (0);
}*/
