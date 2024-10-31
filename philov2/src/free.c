/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:26:08 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/31 16:19:07 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	free_all(t_philo_rout *philo)
{
	int	i;

	i = 0;
	while (i < philo->count)
	{
		pthread_mutex_destroy(&philo->philos[i].left_f);
		i++;
	}
	pthread_mutex_destroy(&philo->msg);
	free(philo->threads);
	free(philo->philos);
}
