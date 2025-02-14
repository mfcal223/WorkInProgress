/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:06:57 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/14 12:15:34 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_status(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	if (!*stack_a)
		return (0);
	if (check_status(*stack_a))
		return (0);
	while (!check_status(*stack_a))
	{
		size_a = stack_size(*stack_a);
		if (size_a < 2)
		{
			display_error();
			return (0);
		}
		else if (size_a == 2)
			sa(stack_a);
		else if (size_a == 3)
			sort_three(stack_a);
		else
			sort_bigger_stack(stack_a, stack_b, size_a);
		if (check_status(*stack_a))
			break ;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		sorted;

	stack_a = NULL;
	stack_b = NULL;
	sorted = 0;
	if (ac < 2)
		return (0);
	stack_a = create_stack(ac, av);
	if (!stack_a)
		return (1);
	normalize_stack(stack_a);
	sorted = sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
