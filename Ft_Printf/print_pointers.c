/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:57 by tturpin           #+#    #+#             */
/*   Updated: 2023/12/04 11:04:21 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_base(char *base)
{
	int	symbol;
	int	j;

	symbol = 0;
	while (base[symbol])
	{
		if (base[symbol] == '+' || base[symbol] == '-')
			return (0);
		j = symbol + 1;
		while (base[j])
		{
			if (base[symbol] == base[j])
				return (0);
			j++;
		}
		symbol++;
	}
	if (symbol < 2)
		return (0);
	return (1);
}

static int	ft_putnbr_base(unsigned long n, char *base, int size)
{
	char	res;
	int		len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	else
	{
		if (n >= (unsigned int)size)
			len += ft_putnbr_base(n / size, base, size);
		res = base[n % size];
		write(1, &res, 1);
		len++;
	}
	return (len);
}

int	print_pointers(unsigned long n)
{
	char			*base;
	int				symbol;
	unsigned int	len;

	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	base = "0123456789abcdef";
	symbol = 0;
	if (!n)
		return (0);
	if ((ft_check_base(base)) == 1)
	{
		while (base[symbol])
			symbol++;
		write(1, "0x", 2);
		len = ft_putnbr_base(n, base, symbol);
		return (len + 2);
	}
	return (0);
}
