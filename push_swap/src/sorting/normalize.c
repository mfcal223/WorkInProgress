/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:34:11 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/17 11:22:44 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->num;
	while (stack)
	{
		if (stack->num < min)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void	normalize_stack(t_stack *stack)
{
	int		value;
	t_stack	*temp;
	t_stack	*min_node;

	value = 0;
	while (true)
	{
		min_node = NULL;
		temp = stack;
		while (temp)
		{
			if (!temp->normal && (!min_node || temp->num < min_node->num))
				min_node = temp;
			temp = temp->next;
		}
		if (!min_node)
			break ;
		min_node->num = value++;
		min_node->normal = true;
	}
}
