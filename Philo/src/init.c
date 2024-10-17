/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:15:34 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/17 13:40:02 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	init_data(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		philo[i].id = i;
		philo[i].time_eaten = 0;
		philo[i].last_time_eat = ft_get_time();
		mutex_handle(philo->left_f, "init");
		if (i + 1 == philo->data->nb_philo)
			philo[i].right_f = (philo - i)->left_f;
		else
			philo[i].right_f = (philo + 1)->left_f;
		if (i % 2)
		{

		}
		i++;
	}
}

void	philo_create(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_create(&philo->thread[i], NULL, philo_routine,
			(void *)&philo[i]);
		i++;
	}
}

void	philo_join(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_join(philo->thread[i], NULL);
		i++;
	}
}
