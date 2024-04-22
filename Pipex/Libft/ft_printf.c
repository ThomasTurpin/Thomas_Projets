/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:19:39 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/18 08:48:11 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += print_char(va_arg(args, int));
	else if (format == 's')
		print_length += print_string(va_arg(args, char *));
	else if (format == 'p')
		print_length += print_pointers(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		print_length += print_int(va_arg(args, int));
	else if (format == 'u')
		print_length += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		print_length += print_hexa_low(va_arg(args, unsigned int));
	else if (format == 'X')
		print_length += print_hexa_up(va_arg(args, unsigned int));
	else if (format == '%')
		print_length += print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
