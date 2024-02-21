/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:29:37 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/21 12:51:34 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_stack_node **src, t_stack_node **dest)
{
	push(src, dest);
	ft_putstr("pa\n");
}

void	do_pb(t_stack_node **src, t_stack_node **dest)
{
	push(src, dest);
	ft_putstr("pb\n");
}
