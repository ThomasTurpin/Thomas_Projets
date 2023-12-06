/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:45:59 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 12:34:23 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	const char	*s1;
	const char	*s2;
	size_t		i;

	s1 = (char *)first;
	s2 = (char *)second;
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
