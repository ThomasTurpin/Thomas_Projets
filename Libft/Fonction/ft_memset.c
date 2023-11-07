/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:10 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/07 09:33:03 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memset(void *c, int val, size_t len)
{
	char	*str;

	str = c;
	while (len)
	{
		*str = (unsigned char)val;
		str++;
		len--;
	}
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	char	test[] = "Coucou ca va";
	printf("Test1: %s\n", test);
	memset(test, '-', 6);
	printf("Test2: %s\n", test);
	return (0);
}*/
