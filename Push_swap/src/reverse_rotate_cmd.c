/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:29:31 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/15 12:19:20 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*before_tail;
	t_stack_node	*tail;

	tail = find_last_node(*stack);
	before_tail = tail->prev;
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr("rrr\n");
}
