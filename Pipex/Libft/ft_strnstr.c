/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:47:26 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/21 14:49:02 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *c, size_t max)
{
	size_t	i;
	size_t	j;
	char	*s1;

	if (src == NULL && max == 0)
		return (0);
	i = 0;
	s1 = (char *)src;
	if (*c == '\0')
		return (s1);
	while (src[i] && i < max)
	{
		j = 0;
		while (c[j] && src[i + j] && src[i + j] == c[j] && (i + j) < max)
			j++;
		if (c[j] == 0)
			return ((char *)src + i);
		i++;
	}
	return (NULL);
}
