/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa_low.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:52:39 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/29 16:21:04 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa_low(unsigned int n)
{
	char	*hexa;
	int		i;

	hexa = "0123456789abcdef";
	i = 0;
	if (n < 16)
		i += write(1, hexa + n, 1);
	else if (n >= 16)
	{
		i += print_hexa_low(n / 16);
		i += print_hexa_low(n % 16);
	}
	return (i);
}
