/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:24:57 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/06 09:35:08 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack_a)->num;
	num2 = (*stack_a)->next->num;
	num3 = (*stack_a)->next->next->num;
	if (num1 > num2 && num2 > num3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (num1 > num3 && num3 > num2)
		ra(stack_a);
	else if (num2 > num1 && num1 > num3)
		rra(stack_a);
	else if (num2 > num3 && num3 > num1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (num3 > num1 && num1 > num2)
		sa(stack_a);
}
