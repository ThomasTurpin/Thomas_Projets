/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:55 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 16:19:11 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(const char *str, char c)
{
	int	i;
	int	trigg;

	i = 0;
	trigg = 0;
	while (*str)
	{
		if (*str != c && trigg == 0)
		{
			trigg = -1;
			i++;
		}
		else if (*str == c)
			trigg = 0;
		str++;
	}
	return (i);
}

static char	*w_dup(const char *str, int start, int end)
{
	char	*m_word;
	int		i;

	m_word = malloc(sizeof(char) * (end - start + 1));
	if (!m_word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		m_word[i++] = str[start++];
	}
	m_word[i] = 0;
	return (m_word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = w_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
