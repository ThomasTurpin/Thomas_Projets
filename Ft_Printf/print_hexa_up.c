/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:54:30 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/28 15:13:25 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_up(unsigned int n)
{
	char	*hexa;
	int		i;

	hexa = "0123456789ABCDEF";
	i = 0;
	if (n < 16)
		i += write(1, hexa + n, 1);
	else if (n >= 16)
	{
		i += print_hexa_up(n / 16);
		i += print_hexa_up(n % 16);
	}
	return (i);
}
