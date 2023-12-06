/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:14:52 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 13:19:42 by tturpin          ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	int		len1;
	int		len2;
	char	*copy;

	if (s1 && s2)
	{
		i = -1;
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		copy = (char *)malloc(sizeof(*s1) * (len1 + len2 + 1));
		if (!copy)
			return (NULL);
		while (s1[++i])
			copy[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			copy[len1] = s2[i];
			len1++;
		}
		copy[len1] = 0;
		return (copy);
	}
	return (NULL);
}
