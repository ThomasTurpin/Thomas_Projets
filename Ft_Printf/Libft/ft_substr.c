/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:11:03 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 15:43:22 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = (char *)malloc(sizeof(*src) * (len + 1));
	if (!new)
		return (NULL);
	while (src[i])
	{
		if (i >= start && j < len)
		{
			new[j] = src[i];
			j++;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}
