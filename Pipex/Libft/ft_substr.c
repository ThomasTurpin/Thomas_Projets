/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:11:03 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/11 11:30:21 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (str == 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }

static int	ft_lenstart(const char *s, int start)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i != start)
		i++;
	while (s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = ft_calloc(1, sizeof(char));
		if (!sub)
			return (NULL);
	}
	else
	{
		new_len = ft_lenstart(s, start);
		if (!(new_len < len))
			new_len = len;
		sub = (char *)malloc((new_len + 1) * sizeof(char));
		if (!sub)
			return (NULL);
		sub[new_len] = 0;
		while (new_len-- > 0)
			sub[new_len] = s[start + new_len];
	}
	return (sub);
}
