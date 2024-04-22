/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:49:42 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/09 09:50:11 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	negative;

	i = 0;
	res = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res * negative);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%d\n", ft_atoi("--123456"));
	printf("%d\n", atoi("-+123456"));
}*/
