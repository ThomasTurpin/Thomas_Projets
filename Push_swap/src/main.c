/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:15 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/27 18:02:20 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!check_input(argv))
		error_free(&a);
	create_stack(&a, argv + 1);
	if (!is_sorted(a, &argc))
	{
		if (get_stack_size(a) == 2)
			do_sa(&a);
		else if (get_stack_size(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	if (argc == 2)
		ft_free_mal(argv);
	free_stack(&a);
	free_stack(&b);
}
