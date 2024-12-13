/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:26:11 by tturpin           #+#    #+#             */
/*   Updated: 2024/11/08 15:48:21 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_eat(t_philo_data *philo)
{
	printf("COUCOU\n");
	ft_msg(philo, philo->id, "has taken a fork");
	pthread_mutex_lock(philo->second_fork);
	ft_msg(philo, philo->id, "has taken a fork");
	ft_msg(philo, philo->id, "is eating");
	philo->die_time = ft_get_time() + philo->data->timetodie
		+ philo->data->timetoeat;
	u_wait(ft_get_time() + philo->data->timetoeat);
	if (philo->data->meallimit != -1)
		philo->times_eaten += 1;
	pthread_mutex_unlock(philo->second_fork);
	pthread_mutex_unlock(philo->first_fork);
}

void	ft_think(t_philo_data *philo)
{
	ft_msg(philo, philo->id, "is thinking");
}

void	ft_sleep(t_philo_data *philo)
{
	ft_msg(philo, philo->id, "is sleeping");
	u_wait(ft_get_time() + philo->data->timetosleep);
}

void	ft_die(t_philo_data *philo)
{
	u_wait(ft_get_time() + philo->data->timetodie);
	ft_msg(philo, philo->id, "died");
	// philo->died = true;
}
