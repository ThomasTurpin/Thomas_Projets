/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:15:11 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/17 14:40:25 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_dinner(t_philo *philo)
{
	mutex_handle(philo->left_f, "lock");
	if (ft_get_time() + philo->data->time_to_eat <= philo->data->time_to_die
		&& (philo->time_eaten < philo->data->nb_meal || philo->data->nb_meal ==
			-1))
		ft_eat(philo);
	else
	{
		mutex_handle(philo->left_f, "unlock");
		if (ft_get_time() + philo->data->time_to_eat > philo->data->time_to_die)
			ft_die(philo);
		return (0);
	}
	if (ft_get_time() + philo->data->time_to_sleep > philo->die_time)
	{
		philo->die_time -= philo->data->time_to_eat;
		ft_die(philo);
	}
	else
		ft_sleep(philo);
	ft_think(philo);
	return (1);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->die_time = philo->data->start + philo->data->time_to_die;
	if (philo->id % 2 == 0)
		usleep(ft_get_time() + philo->data->time_to_eat);
	while (1)
	{
		if (ft_dinner(philo) == 0 || philo->data->is_dead != -1)
			return (NULL);
	}
	return (NULL);
}
