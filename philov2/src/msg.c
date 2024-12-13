/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:04:46 by tturpin           #+#    #+#             */
/*   Updated: 2024/11/08 14:11:58 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	ft_msg(t_philo_data *philo, int id, const char *actions)
{
	long long	time;

	pthread_mutex_lock(philo->m);
	time = ft_get_time() - philo->data->time_starting;
	if (ft_strcmp(actions, "has taken a fork"))
		printf("%lld %d %s\n", time, id, actions);
	else if (ft_strcmp(actions, "is eating"))
		printf("%lld %d %s\n", time, id, actions);
	else if (ft_strcmp(actions, "is sleeping"))
		printf("%lld %d %s\n", time, id, actions);
	else if (ft_strcmp(actions, "is thinking"))
		printf("%lld %d %s\n", time, id, actions);
	else if (ft_strcmp(actions, "died"))
		printf("%lld %d %s\n", time, id, actions);
}
