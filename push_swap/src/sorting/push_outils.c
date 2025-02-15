/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_outils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:23 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/14 12:29:37 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*target_a(t_stack *stack_b_node, t_stack *stack_a)
{
	t_stack	*target;
	t_stack	*current;
	int		friend;

	target = NULL;
	current = stack_a;
	friend = INT_MAX;
	while (current)
	{
		if (current->num > stack_b_node->num && current->num < friend)
		{
			friend = current->num;
			target = current;
		}
		current = current->next;
	}
	if (!target)
	{
		target = find_smallest_node(stack_a);
	}
	return (target);
}

int	get_push_cost(t_stack *node, t_stack *src, t_stack *dst)
{
	int		cost_a;
	int		cost_b;
	t_stack	*target;

	if (!dst)
		return (0);
	target = target_a(node, dst);
	if (!target)
		return (0);
	cost_a = count_rotations(src, node);
	cost_b = count_rotations(dst, target);
	node->cost = cost_a + cost_b;
	node->target = target;
	return (node->cost);
}

t_stack	*find_cheapest(t_stack **src, t_stack **dst)
{
	t_stack	*cheapest;
	t_stack	*current;

	if (!*src || !*dst)
		return (NULL);
	cheapest = *src;
	if (!cheapest)
		return (NULL);
	cheapest->cost = get_push_cost(cheapest, *src, *dst);
	current = (*src)->next;
	while (current)
	{
		current->cost = get_push_cost(current, *src, *dst);
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	cheapest->cheap = true;
	update_index_abmedian(src);
	update_index_abmedian(dst);
	return (cheapest);
}

void	check_head_min(t_stack **stack_a)
{
	t_stack	*smallest;
	int		size;

	size = stack_size(*stack_a);
	smallest = find_smallest_node(*stack_a);
	if (*stack_a == smallest)
		return ;
	while (smallest->index != 0)
	{
		if (smallest->index <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		update_index_abmedian(stack_a);
	}
}
