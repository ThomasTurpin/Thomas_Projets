/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 09:24:55 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/14 17:18:13 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char a, char b)
{
	if (a == b)
		return (1);
	return (0);
}

int	w_len(char *s, char charset)
{
	int	i;

	i = 0;
	while (s[i] && ft_count(s[i], charset) == 0)
		i++;
	return (i);
}

int	first_len(char *s, char charset)
{
	int	i;
	int	flen;
	int	is_word;

	flen = 0;
	i = 0;
	is_word = 0;
	while (s[i])
	{
		if (ft_count(s[i], charset) >= 1)
			is_word = 0;
		if (ft_count(s[i], charset) == 0 && is_word == 0)
		{
			flen++;
			is_word = 1;
		}
		i++;
	}
	return (flen);
}

void	word_copy(char *dest, char *s, char charset)
{
	int	i;

	i = 0;
	while (s[i] && ft_count(s[i], charset) == 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)

{
	char	**dest;
	int		j;
	int		i;
	int		new_word;

	dest = (char **)malloc((first_len((char *)s, c) + 1) * sizeof(char *));
	if (dest == NULL)
		return (NULL);
	i = -1;
	j = 0;
	new_word = 0;
	while (s[++i])
	{
		if (new_word == 0 && ft_count(s[i], c) == 0)
		{
			dest[j] = malloc((w_len((char *)&s[i], c) + 1) * sizeof(char));
			new_word = 1;
			word_copy(dest[j], (char *)&s[i], c);
			j++;
		}
		if (ft_count(s[i], c) >= 1)
			new_word = 0;
	}
	dest[first_len((char *)s, c)] = NULL;
	return (dest);
}
