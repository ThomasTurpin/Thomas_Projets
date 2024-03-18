/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:31:59 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/13 16:46:33 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mal;

	mal = (t_list *)malloc(sizeof(t_list) * 1);
	if (!mal)
		return (NULL);
	mal->content = content;
	mal->next = NULL;
	return (mal);
}
