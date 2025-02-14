/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:37:33 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/06 09:37:34 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	ft_printf("Printing the Stack: ");
	current = stack;
	if (!current)
	{
		ft_printf("stack is empty.\n");
		return ;
	}
	while (current)
	{
		ft_printf("%d, ", current->num);
		current = current->next;
	}
	ft_printf("\n");
}
