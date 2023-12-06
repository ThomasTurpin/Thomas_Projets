/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:33:25 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 15:39:57 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*n_mall;

	if (nmemb * size == 0)
	{
		n_mall = malloc(0);
		if (!n_mall)
			return (NULL);
		return (n_mall);
	}
	else if (!nmemb || !size || (nmemb * size) / size != nmemb)
		return (NULL);
	n_mall = (void *)malloc(nmemb * size);
	if (!n_mall)
		return (NULL);
	ft_bzero(n_mall, (nmemb * size));
	return (n_mall);
}
