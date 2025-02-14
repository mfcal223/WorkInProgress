/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/29 13:11:14 by mcalciat          #+#    #+#             */
/*   Updated: 2025/01/29 13:10:45 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack_size(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	second->next = first;
	second->previous = NULL;
	first->previous = second;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

/*
int	main(void)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	// Populate stacks A and B for testing
	// Example: stack_a = [4, 3, 2], stack_b = [8, 7, 6]
	stack_a = populate_stack((int[]){4, 3, 2}, 3);
	stack_b = populate_stack((int[]){8, 7, 6}, 3);

	// Before ss
	ft_printf("Before ss:\n");
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");

	// Perform ss
	ss(&stack_a, &stack_b);

	// After ss
	ft_printf("After ss:\n");
	print_stack(stack_a, "Stack A");
	print_stack(stack_b, "Stack B");

	// Free stacks
	free_stack(stack_a);
	free_stack(stack_b);

	return (0);
}*/
