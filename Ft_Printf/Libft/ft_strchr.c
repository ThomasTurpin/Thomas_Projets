/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:25 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/13 09:43:52 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
