/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:14:59 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/08 15:26:09 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *str, int searched)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)searched)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	a[] = "couvcou comvment ca va";
	char	b;
	char	*result;

	b = 'v';
	result = ft_strrchr(a, b);
	printf("%s\n", result);
}*/
