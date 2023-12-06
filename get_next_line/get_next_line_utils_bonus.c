/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:47:48 by tturpin           #+#    #+#             */
/*   Updated: 2023/12/05 14:31:08 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	*ft_strchr(const char *str, int searched)
{
	while (*str != '\0')
	{
		if ((unsigned char)*str == (unsigned char)searched)
			return ((char *)str);
		str++;
	}
	if (searched == 0)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*mall;
	int		j;

	mall = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	j = 0;
	if (!mall)
		return (NULL);
	while (src[j])
	{
		mall[j] = src[j];
		j++;
	}
	mall[j] = '\0';
	return (mall);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
