/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:25:59 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/08 13:16:24 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)dest;
	while (i < size)
	{
		*str = *(char *)src;
		str++;
		src++;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[10] = "asdfghjklm";
	char	dest[10];
	char	*result;

	result = ft_memcpy(dest, src, 5);
	printf("%s\n", result);
	return (0);
}*/
