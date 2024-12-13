/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:25:51 by tturpin           #+#    #+#             */
/*   Updated: 2024/11/25 08:24:07 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

// int	ft_dinner(t_philo_data *philo)
// {
// 	// pthread_mutex_lock(philo->first_fork);
// 	// pthread_mutex_unlock(philo->first_fork);
// 	printf("%d in ft_dinner\n", philo->id);
// 	ft_msg(philo, philo->id, "has taken a fork");
// 	if (ft_get_time() + philo->data->timetoeat < philo->die_time
// 		&& (philo->times_eaten <= philo->data->meallimit
// 			|| philo->data->meallimit == -1))
// 				ft_eat(philo);
// 	else
// 	{
// 		printf("Not Eat\n");
// 		pthread_mutex_unlock(philo->first_fork);
// 		if (ft_get_time() + philo->data->timetoeat > philo->die_time)
// 			ft_die(philo);
// 		return (0);
// 	}
// 	if (ft_get_time() + philo->data->timetosleep > philo->die_time)
// 	{
// 		philo->die_time -= philo->data->timetoeat;
// 		ft_die(philo);
// 		return (0);
// 	}
// 	else
// 		ft_sleep(philo);
// 	ft_think(philo);
// 	return (1);
// }

int	ft_dinner(t_philo_data *philo)
{
	// pthread_mutex_lock(philo->first_fork);
	// pthread_mutex_unlock(philo->first_fork);
	printf("%d in ft_dinner\n", philo->id);
	ft_msg(philo, philo->id, "has taken a fork");
	ft_eat(philo);
	printf("Not Eat\n");
	pthread_mutex_unlock(philo->first_fork);
	if (ft_get_time() + philo->data->timetoeat > philo->die_time)
		ft_die(philo);
	if (ft_get_time() + philo->data->timetosleep > philo->die_time)
	{
		philo->die_time -= philo->data->timetoeat;
		ft_die(philo);
		return (0);
	}
	else
		ft_sleep(philo);
	ft_think(philo);
	return (1);
}

void	*philo_routine(void *philo)
{
	t_philo_data	*rout;
	int				i;

	rout = (t_philo_data *)philo;
	i = 0;
	if (rout->id % 2 == 0)
		u_wait(ft_get_time() + rout->data->timetoeat);
	printf("%d in rout\n", rout->id);
	while (1)
	{
		if (ft_dinner(rout) == 0 || rout->died == true)
			return (NULL);
		i++;
	}
	return (NULL);
}
