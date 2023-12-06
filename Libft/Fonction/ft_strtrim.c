/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:04:27 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 16:32:29 by tturpin          ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*copy;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) && len > 0)
		len--;
	copy = ft_substr(s1, 0, len);
	return (copy);
}
