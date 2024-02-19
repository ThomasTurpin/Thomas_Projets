/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:29:26 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/15 12:19:26 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = find_last_node(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_stack_node **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	do_rb(t_stack_node **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	do_rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr("rr\n");
}
