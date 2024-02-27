/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:10:42 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/26 15:01:32 by tturpin          ###   ########.fr       */
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

void	nb_five(t_stack_node **a, t_stack_node **b)
{
	while (get_stack_size(*a) > 3)
	{
		init_all(*a, *b);
		rotate_one(a, find_smallest(*a), 'a');
		do_pb(b, a);
	}
}
