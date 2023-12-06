/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:01:10 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 11:00:03 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *c, int val, size_t len)
{
	char	*str;

	str = c;
	while (len)
	{
		*str = (unsigned char)val;
		str++;
		len--;
	}
	return (c);
}
