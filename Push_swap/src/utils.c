/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:26:09 by tturpin           #+#    #+#             */
/*   Updated: 2024/02/19 15:31:36 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

// long	ft_atol(const char *str)
// {
// 	size_t	i;
// 	size_t	res;
// 	size_t	negative;

// 	i = 0;
// 	res = 0;
// 	negative = 1;
// 	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
// 		i++;
// 	if (str[i] == '-')
// 		negative *= -1;
// 	if (str[i] == '+' || str[i] == '-')
// 		i++;
// 	while (str[i] && str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = (res * 10) + str[i] - 48;
// 		i++;
// 	}
// 	return (res * negative);
// }

long	ft_atol(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	if (!dest || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && --size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
