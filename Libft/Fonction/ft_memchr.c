/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:46:31 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 15:40:22 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memBlock, int searchedChar, size_t size)
{
	int		i;
	char	*mem;

	i = 0;
	mem = (char *)memBlock;
	while (size--)
	{
		if (mem[i] == searchedChar)
			return (mem + i);
		i++;
	}
	return (NULL);
}
