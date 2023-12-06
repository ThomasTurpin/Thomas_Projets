/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:46:31 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/13 09:48:36 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memBlock, int searchedChar, size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)memBlock;
	while (size--)
	{
		if (*mem == (unsigned char)searchedChar)
			return (mem);
		mem++;
	}
	return (NULL);
}
