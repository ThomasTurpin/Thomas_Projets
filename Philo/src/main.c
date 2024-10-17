/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:18:44 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/17 14:42:30 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		check_input(&data, argv);
		data.start = ft_get_time();
		if (data.nb_philo == 1)
		{
			printf("Philo 1 take a fork");
			usleep((data.start + data.time_to_die) * 1000);
			printf("%lld %d died \n", ft_get_time() - data.start, 1);
		}
		else
		{
			init_data(data.philo);
			philo_create(data.philo);
			philo_join(data.philo);
		}
		end_free(data.philo);
	}
	else
	{
		error_msg("Not the right input.");
		end_free(data.philo);
	}
}
