/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:15:48 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/17 13:40:35 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	error_msg(const char *msg)
{
	printf("%s\n", msg);
	exit (0);
}

void	end_free(t_philo *philo)
{
	// int	i;

	// i = 0;
	// // while (i < philo->data->nb_philo)
	// // {
	// // 	mutex_handle(philo->left_f, "destroy");
	// // 	i++;
	// // }
	if (philo)
		free(philo);
}

void	ft_print(t_philo *philo, const char *msg)
{
	printf(" %lld %d %s\n", ft_get_time() - philo->data->start, philo->id, msg);
}
