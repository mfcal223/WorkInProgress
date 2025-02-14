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
/*   Created: 2025/01/29 10:51:14 by mcalciat          #+#    #+#             */
/*   Updated: 2025/01/29 10:49:45 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	else
	{
		*src = NULL;
	}
	temp->next = *dest;
	if (*dest)
		(*dest)->previous = temp;
	*dest = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	push(stack_a, stack_b);
	ft_printf("pa\n");
	if (!*stack_b || stack_size(*stack_b) == 0)
	{
		*stack_b = NULL;
	}
	else
	{
		update_index_abmedian(stack_b);
	}
	update_index_abmedian(stack_a);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (!*stack_a)
		return ;
	push(stack_b, stack_a);
	ft_printf("pb\n");
	if (!*stack_a)
		*stack_a = NULL;
	update_index_abmedian(stack_b);
	update_index_abmedian(stack_a);
}
