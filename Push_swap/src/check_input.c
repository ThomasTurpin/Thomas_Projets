/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:11:56 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/19 10:17:39 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i +1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}


int	duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && nb_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	only_zero(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i])
		return (0);
	return (1);
}

int	check_input(char **argv)
{
	int	i;
	int	zero;

	zero = 0;
	i = 1;
	while (argv[i])
	{
		if (!argv_number(argv[i]))
			return (0);
		zero += only_zero(argv[i]);
		i++;
	}
	if (zero > 1)
		return (0);
	if (duplicates(argv))
		return (0);
	return (1);
}
