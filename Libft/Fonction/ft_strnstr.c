/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:47:26 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 15:44:18 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t max)
{
	size_t	i;
	size_t	j;
	char	*s1;

	i = 0;
	s1 = (char *)src;
	if (*to_find == '\0')
		return (s1);
	while (src[i] && i < max)
	{
		if (src[i] == to_find[0])
		{
			j = 0;
			while (src[i + j] == to_find[j] && to_find[j])
				j++;
			if (to_find[j] == 0)
				return (&s1[i]);
		}
		i++;
	}
	return (0);
}
