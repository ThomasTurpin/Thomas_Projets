/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:45:59 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/13 10:23:30 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)first;
	s2 = (unsigned char *)second;
	i = 0;
	while (s1[i] && s1[i] == s2[i] && length > 0)
	{
		i++;
		length--;
	}
	if (length == 0)
		return (0);
	return (s1[i] - s2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "Test2";
	char	s2[] = "Test1";
	printf("%d\n", ft_strncmp(s1, s2, 5));
}*/
