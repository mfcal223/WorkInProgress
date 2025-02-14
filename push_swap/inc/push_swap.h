/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcalciat <mcalciat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:20:11 by mcalciat          #+#    #+#             */
/*   Updated: 2025/02/14 12:38:00 by mcalciat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft_printf/inc/ft_printf.h"
# include "../libft_printf/inc/libft.h"

typedef struct stack_element
{
	int						size;		//size of the stack
	int						num;		//value
	int						index;		//track the position
	int						cost;		//push cost
	bool					abmedian;	//to ra or rra when pushing from B
	bool					cheap;		//is it the cheapest or not?
	struct stack_element	*target;	//where an element should go
	struct stack_element	*next;		// ptr to next node
	struct stack_element	*previous;	//not sure about this or only next
}		t_stack;

/* OPERATIONS */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	push(t_stack **dest, t_stack **src);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack);

/* SORTING */
/* normalize */
int		find_min(t_stack *stack);
void	normalize_stack(t_stack *stack);

/* push outils */
t_stack	*target_a(t_stack *stack_b_node, t_stack *stack_a);
int		get_push_cost(t_stack *node, t_stack *src, t_stack *dst);
t_stack	*find_cheapest(t_stack **src, t_stack **dst);
void	check_head_min(t_stack **stack_a);

/* sort bigger stack + 2 statics functions  */
void	push_cheap_b(t_stack **st_b, t_stack *cheap, t_stack **st_a, int sz_b);
void	push_b_to_a(t_stack **stack_b, t_stack **stack_a);
void	sort_bigger_stack(t_stack **stack_a, t_stack **stack_b, int size_a);

/* sort 3 */
void	sort_three(t_stack **stack_a);

/* sorting outils */
int		count_rotations(t_stack *stack, t_stack *node);
t_stack	*find_smallest_node(t_stack *stack);
t_stack	*find_largest_node(t_stack *stack);
void	reset_cheap_flag(t_stack *stack);
void	update_index_abmedian(t_stack **stack);

/* STACK_HANDLING */
/* create_stack */
t_stack	*create_node(int num);
void	node_links(t_stack **head, t_stack **curr, t_stack *new_node);
t_stack	*populate_stack(int *array, int count);
t_stack	*create_stack(int ac, char **av);

/* atol */
int		ft_atol(const char *str);
int		ft_isspace(char c);
/* parse_num */
int		*parse_num(int ac, char **av, int *count);

/* print stack */
void	print_stack(t_stack *stack);

/* split_num */
void	free_split(char **array);
int		*convert_to_numbers(char **array_words, int count);
int		*split_num(char *string, int *count);

/* stack outils  */
void	free_stack(t_stack **stack);
t_stack	*find_last(t_stack *stack);
int		stack_size(t_stack *src);
void	display_error(void);

/* validate input  */
int		is_empty_or_null(char *string);
int		has_invalid_chars(char *string);
int		is_out_of_range(char *string);
int		is_valid_integer(char *string);
int		check_duplicates(int *array_number, int count);

/* push swap main file */
int		check_status(t_stack *stack_a);
int		sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif
