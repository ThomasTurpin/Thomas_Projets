/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:25:16 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/31 16:19:13 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_philo_var		*var;
	t_philo_rout	philo;

	var = malloc(sizeof(t_philo_var));
	if (init_var(argc, argv, var))
	{
		printf("Wrong Arguments\n");
		return (0);
	}
	var->time_starting = ft_get_time();
	init_philo(&philo, var);
	if (var->nb_philo == 1)
	{
		printf("%lld %d has taken a fork\n", ft_get_time() - var->time_starting,
			1);
		u_wait(ft_get_time() + var->timetodie);
		printf("%lld %d died\n", ft_get_time() - var->time_starting, 1);
		free(var);
		free_all(&philo);
		return (0);
	}
	philo_create(&philo);
	philo_join(&philo);
	free (var);
	free_all(&philo);
	return (0);
}
