/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:25 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/08 15:32:42 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strchr(const char *str, int searched)
{
	char	*s;

	s = (char *)str;
	while (*s != searched)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	a[] = "coucou comment ca va";
	char	b;
	char	*result;

	b = 'a';
	result = ft_strchr(a, b);
	printf("%s\n", result);
	printf("%s\n", strchr(a, b));
}*/
