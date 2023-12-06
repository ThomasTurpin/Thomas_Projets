/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:33:01 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/21 11:49:42 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
