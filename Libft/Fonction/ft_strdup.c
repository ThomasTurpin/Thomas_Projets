/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:01 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 12:21:43 by tturpin          ###   ########.fr       */
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
