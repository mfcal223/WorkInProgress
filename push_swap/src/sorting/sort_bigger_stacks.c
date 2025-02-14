/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_stacks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:25:23 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/14 12:38:46 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_rotation(t_stack **st_a, t_stack **st_b, t_stack *cheap)
{
	if (cheap->abmedian)
	{
		rr(st_a, st_b);
		update_index_abmedian(st_b);
		update_index_abmedian(st_a);
	}
	else
	{
		rrr(st_a, st_b);
		update_index_abmedian(st_b);
		update_index_abmedian(st_a);
	}
}

static void	single_rotation(t_stack **st_a, t_stack **st_b, t_stack *cheap,
		int *sizes)
{
	if (cheap->index != 0)
	{
		if (cheap->index <= sizes[0] / 2)
			rb(st_b);
		else
			rrb(st_b);
		update_index_abmedian(st_b);
	}
	if (cheap->target->index != 0)
	{
		if (cheap->target->index <= sizes[1] / 2)
			ra(st_a);
		else
			rra(st_a);
		update_index_abmedian(st_a);
	}
}

void	push_cheap_b(t_stack **st_b, t_stack *cheap, t_stack **st_a, int sz_b)
{
	int	sizes[2];

	if (!cheap)
		return ;
	sizes[0] = sz_b;
	sizes[1] = stack_size(*st_a);
	while (cheap->index != 0 || cheap->target->index != 0)
	{
		if ((cheap->index != 0 && cheap->target->index != 0)
			&& cheap->abmedian == cheap->target->abmedian)
			double_rotation(st_a, st_b, cheap);
		else
			single_rotation(st_a, st_b, cheap, sizes);
	}
	pa(st_a, st_b);
}

void	push_b_to_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*cheapest;
	int		size_b;

	while (*stack_b && stack_size(*stack_b) > 0)
	{
		if (!*stack_b || stack_size(*stack_b) == 0)
			return ;
		cheapest = find_cheapest(stack_b, stack_a);
		if (!cheapest)
			return ;
		size_b = stack_size(*stack_b);
		push_cheap_b(stack_b, cheapest, stack_a, size_b);
		reset_cheap_flag(*stack_a);
		if (stack_size(*stack_b) == 0)
			break ;
	}
}

void	sort_bigger_stack(t_stack **stack_a, t_stack **stack_b, int size_a)
{
	while (size_a > 3 && !check_status(*stack_a))
	{
		pb(stack_b, stack_a);
		size_a--;
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
}
