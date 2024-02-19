/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:10:42 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/15 12:41:31 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		do_ra(a);
	else if ((*a)-> next == highest_node)
		do_rra(a);
	if ((*a)->value > (*a)->next->value)
		do_sa(a);
}

void	sort_choose(t_stack_node **a, t_stack_node **b, int stack_size)
{
	if (stack_size == 3 && !(is_sorted(*a)))
		tiny_sort(a);
	if (stack_size > 5 && !(is_sorted(*a)))
	{
		push_swap(a, b);
	}
}
