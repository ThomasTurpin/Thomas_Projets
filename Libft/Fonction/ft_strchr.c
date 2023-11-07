/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:07:25 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/07 10:14:25 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strchr( const char *str, int searched)
{
	char	*s;

	s = (char *) str;
	while (*s != searched)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}
