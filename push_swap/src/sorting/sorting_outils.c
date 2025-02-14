/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_outils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:33:29 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/12 15:00:28 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_rotations(t_stack *stack, t_stack *node)
{
	int	size;
	int	index;

	size = stack_size(stack);
	update_index_abmedian(&stack);
	index = node->index;
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

t_stack	*find_smallest_node(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	smallest = stack;
	current = stack->next;
	while (current)
	{
		if (current->num < smallest->num)
		{
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

t_stack	*find_largest_node(t_stack *stack)
{
	t_stack	*largest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	largest = stack;
	current = stack->next;
	while (current)
	{
		if (current->num > largest->num)
		{
			largest = current;
		}
		current = current->next;
	}
	return (largest);
}

void	reset_cheap_flag(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->cheap = false;
		current = current->next;
	}
}

void	update_index_abmedian(t_stack **stack)
{
	int		size;
	int		i;
	t_stack	*current;

	i = 0;
	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	current = *stack;
	while (current)
	{
		current->index = i;
		if (current->index <= size / 2)
			current->abmedian = true;
		else
			current->abmedian = false;
		current = current->next;
		i++;
	}
}
