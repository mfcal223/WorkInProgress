/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:06:17 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/12 14:58:36 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*find_last(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (0);
	last = stack;
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

int	stack_size(t_stack *src)
{
	int	count;

	count = 0;
	while (src)
	{
		count++;
		src = src->next;
	}
	return (count);
}

void	display_error(void)
{
	ft_putendl_fd("Error", 2);
}
