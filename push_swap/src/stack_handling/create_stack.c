/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:26:32 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/17 16:19:07 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int num)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = -1;
	new_node->cost = 0;
	new_node->abmedian = false;
	new_node->cheap = false;
	new_node->normal = false;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	node_links(t_stack **head, t_stack **curr, t_stack *new_node)
{
	if (!*head)
	{
		*head = new_node;
		*curr = new_node;
	}
	else
	{
		(*curr)->next = new_node;
		new_node->previous = *curr;
		*curr = new_node;
	}
}

t_stack	*populate_stack(int *array, int count)
{
	t_stack	*head;
	t_stack	*curr;
	t_stack	*new_node;
	int		i;

	head = NULL;
	curr = NULL;
	i = 0;
	if (count < 2)
		return (NULL);
	while (i < count)
	{
		new_node = create_node(array[i]);
		if (!new_node)
		{
			free_stack(&head);
			return (NULL);
		}
		node_links(&head, &curr, new_node);
		i++;
	}
	return (head);
}

t_stack	*create_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		*array_number;
	int		count;

	count = 0;
	stack_a = NULL;
	array_number = NULL;
	if (ac == 2)
		array_number = split_num(av[1], &count);
	else
		array_number = parse_num(ac, av, &count);
	if (!array_number || count < 2)
		return (NULL);
	if (check_duplicates(array_number, count))
	{
		free(array_number);
		return (NULL);
	}
	stack_a = populate_stack(array_number, count);
	free(array_number);
	return (stack_a);
}
