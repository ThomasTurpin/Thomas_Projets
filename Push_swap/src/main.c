/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:15 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/15 16:40:03 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack_node *top)
{
	while (top != NULL)
	{
		printf("%d\n", top->value);
		top = top->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				stack_size;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!check_input(argv))
		error(NULL, NULL);
	create_stack(&a, argv + 1);
	stack_size = get_stack_size(a);
	sort_choose(&a, &b, stack_size);
	print_stack(a);
}
