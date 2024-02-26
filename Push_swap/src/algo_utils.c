/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 08:46:29 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/26 10:42:33 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack_node *stack)
{
	int	i;
	int	half;

	i = 0;
	if (stack == NULL)
		return ;
	half = get_stack_size(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= half)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack_node *a, t_stack_node *b)
{
	long			best_match;
	t_stack_node	*current_node;
	t_stack_node	*target_node;

	while (b)
	{
		best_match = LONG_MAX;
		current_node = a;
		while (current_node)
		{
			if (current_node->value > b->value
				&& current_node->value < best_match)
			{
				best_match = current_node->value;
				target_node = current_node;
			}
			current_node = current_node->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(a);
	len_b = get_stack_size(b);
	while (b)
	{
		b->push_price = b->position;
		if (!(b->above_median))
			b->push_price = len_b - (b->position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->position;
		else
			b->push_price += len_a - (b->target_node->position);
		b = b->next;
	}
}

void	find_cheapest(t_stack_node *b)
{
	long			best_value;
	t_stack_node	*best_node;

	if (b == NULL)
		return ;
	best_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_value)
		{
			best_value = b->push_price;
			best_node = b;
		}
		b = b->next;
	}
	best_node->cheapest = true;
}

void	init_all(t_stack_node *a, t_stack_node *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_cost(a, b);
	find_cheapest(b);
}
