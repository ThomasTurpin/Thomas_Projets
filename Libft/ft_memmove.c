/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:40:11 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/21 14:01:55 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	if (d > s)
	{
		while (size > 0)
		{
			d[size - 1] = s[size - 1];
			size--;
		}
	}
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[15] = "fffffasdfgajklm";
	char	dest[10];
	char	*result;

	result = ft_memmove(dest, src, 2);
	printf("%s\n", result);
	return (0);
}*/
