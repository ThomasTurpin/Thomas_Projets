/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:29:21 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/14 12:01:53 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	do_sa(t_stack_node **a)
{
	swap(*a);
	ft_putstr("sa\n");
}

void	do_sb(t_stack_node **b)
{
	swap(*b);
	ft_putstr("sb\n");
}

void	do_ss(t_stack_node **a, t_stack_node **b)
{
	swap(*a);
	swap(*b);
	ft_putstr("ss\n");
}
