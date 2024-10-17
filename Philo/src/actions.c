/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:38:27 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/17 08:57:58 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_eat(t_philo *philo)
{
	ft_print(philo, "has taken a fork");
	mutex_handle(philo->right_f, "lock");
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->die_time = ft_get_time() + philo->data->time_to_die
		+ philo->data->time_to_eat;
	usleep(ft_get_time() + philo->data->time_to_eat);
	if (philo->data->nb_meal != -1)
		philo->time_eaten += 1;
	mutex_handle(philo->right_f, "unlock");
	mutex_handle(philo->left_f, "unlock");
}

void	ft_think(t_philo *philo)
{
	ft_print(philo, "is thinking.");
}

void	ft_sleep(t_philo *philo)
{
	usleep(ft_get_time() + philo->data->time_to_sleep);
	ft_print(philo, "is sleeping");
}

void	ft_die(t_philo *philo)
{
	usleep(ft_get_time() + philo->data->time_to_die);
	ft_print(philo, "is dead");
}
