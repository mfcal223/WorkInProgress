/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:23 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/14 10:03:47 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_cheap_b(t_stack **st_b, t_stack *cheap, t_stack **st_a, int sz_b)
{
	int	size_a;

	size_a = stack_size(*st_a);
	if (!cheap)
		return ;
	while (cheap->index != 0 || cheap->target->index != 0)
	{
		if (cheap->index != 0)
		{
			if (cheap->index <= sz_b / 2)
				rb(st_b);
			else
				rrb(st_b);
			update_index_abmedian(st_b);
		}
		if (cheap->target->index != 0)
		{
			if (cheap->target->index <= size_a / 2)
				ra(st_a);
			else
				rra(st_a);
			update_index_abmedian(st_a);
		}
	}
	pa(st_a, st_b);
	//ft_printf("stack A: ");//erase
	//print_stack(*st_a);//erase
	//ft_printf("stack B: ");//erase
	//print_stack(*st_b);//erase
}

void	push_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*cheapest;
	int		size_b;

	while (*stack_b && stack_size(*stack_b) > 0)
	{
		if (!*stack_b || stack_size(*stack_b) == 0)
			return ;
		cheapest = find_cheapest(stack_b, stack_a, 'b');
		if (!cheapest)
			return ;
		size_b = stack_size(*stack_b);
		push_cheap_b(stack_b, cheapest, stack_a, size_b);
		reset_cheap_flag(*stack_a);
		if (stack_size(*stack_b) == 0)
			break ;
	}
}

void	push_cheap_a(t_stack **st_a, t_stack *cheap, t_stack **st_b, int sz_a)
{
	int	size_b;

	size_b = stack_size(*st_b);
	if (!cheap)
		return ;

	while ((cheap->index != 0 || cheap->target->index != 0) && sz_a > 3)
	{
		if (cheap->index != 0)
		{
			if (cheap->index <= sz_a / 2)
				ra(st_a);
			else
				rra(st_a);
			update_index_abmedian(st_a);
		}
		if (cheap->target->index != 0)
		{
			if (cheap->target->index <= size_b / 2)
				rb(st_b);
			else
				rrb(st_b);
			update_index_abmedian(st_b);
		}
	}
	pb(st_b, st_a);
	//ft_printf("stack A: ");//erase
	//print_stack(*st_a);//erase
	//ft_printf("stack B: ");//erase
	//print_stack(*st_b);//erase
}

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(stack_a, stack_b, 'a');
	if (!cheapest)
		return ;
	push_cheap_a(stack_a, cheapest, stack_b, size_a);
	reset_cheap_flag(*stack_b);
}

void	sort_bigger_stack(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	int	size_b;

	size_b = 0;
	while (size_a > 3 && size_b < 2 && !check_status(*stack_a))
	{
		pb(stack_b, stack_a);
		size_b++;
		size_a--;
	}
	while (stack_size(*stack_a) > 3 && *stack_b && !check_status(*stack_a))
	{
		push_a_to_b(stack_a, stack_b, size_a);
		stack_size(*stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		if (stack_size(*stack_b) == 0)
			break ;
		push_b_to_a(stack_b, stack_a);
		stack_size(*stack_b);

	}
	check_head_min(stack_a);
	//ft_printf("stack A: ");//erase
	//print_stack(*stack_a);//erase
}
