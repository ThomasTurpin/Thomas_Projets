/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:04:37 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/15 15:00:38 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
	{
		write(1, "Yo", 2);
		do_rr(a, b);
	}
	set_position(*a);
	set_position(*b);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		do_rrr(a, b);
	set_position(*a);
	set_position(*b);
}

void	rotate_one(t_stack_node **stack, t_stack_node *head_node,
		char stack_name)
{
	while (*stack != head_node)
	{
		if (head_node->above_median)
		{
			if (stack_name == 'a')
				do_ra(stack);
			if (stack_name == 'b')
				do_rb(stack);
		}
		else if (!(head_node->above_median))
		{
			if (stack_name == 'a')
				do_rra(stack);
			if (stack_name == 'b')
				do_rrb(stack);
		}
	}
}

void	do_moves(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
	{
		rotate_both(a, b, cheapest_node);
	}
	if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
	{
		reverse_rotate_both(a, b, cheapest_node);
	}
	rotate_one(a, cheapest_node->target_node, 'a');
	rotate_one(b, cheapest_node, 'b');
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	// t_stack_node	*tiniest_node;

	len_a = get_stack_size(*a);
	while (len_a-- > 3)
		do_pb(a, b);
	tiny_sort(a);
	if (*b)
	{
		init_all(*a, *b);
		do_moves(a, b);
	}
}
