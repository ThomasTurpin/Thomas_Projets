/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:38:42 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/08 11:53:21 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

long long	ft_get_time(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (-1);
	return (((long long)t.tv_sec * 1000) + ((long long)t.tv_usec / 1000));
}
