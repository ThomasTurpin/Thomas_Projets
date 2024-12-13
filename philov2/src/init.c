/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:26:04 by tturpin           #+#    #+#             */
/*   Updated: 2024/11/08 13:56:00 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	init_var(int argc, char **argv, t_philo_var *var)
{
	if (argc == 5 || argc == 6)
	{
		if (ft_atoi(argv[1], &var->nb_philo))
			return (1);
		if (ft_atoll(argv[2], &var->timetodie))
			return (1);
		if (ft_atoll(argv[3], &var->timetoeat))
			return (1);
		if (ft_atoll(argv[4], &var->timetosleep))
			return (1);
		if (argc == 6)
		{
			if (ft_atoi(argv[5], &var->meallimit))
				return (1);
		}
		else
			var->meallimit = -1;
		if (var->nb_philo == 0 || var->meallimit == 0)
			return (1);
		return (0);
	}
	else
		return (1);
}

void	init_data_philo(t_philo_data *philo, t_philo_var *var, int i)
{
	philo->id = i;
	philo->times_eaten = 0;
	philo->die_time = philo->data->time_starting + philo->data->timetoeat;
	philo->died = false;
	pthread_mutex_init(&philo->left_f, NULL);
	if (i + 1 == var->nb_philo)
		philo->right_f = &(philo - i)->left_f;
	else
		philo->right_f = &(philo + 1)->left_f;
	philo->first_fork = &philo->left_f;
	philo->second_fork = philo->right_f;
	if (i % 2)
	{
		philo->first_fork = philo->right_f;
		philo->second_fork = &philo->left_f;
	}
}

int	init_philo(t_philo_rout *philo_st, t_philo_var *var)
{
	int	i;

	i = 0;
	philo_st->philos = malloc(sizeof(t_philo_data) * var->nb_philo);
	philo_st->threads = malloc(sizeof(pthread_t) * var->nb_philo);
	if (!philo_st->philos || !philo_st->threads)
	{
		free_all(philo_st);
		return (1);
	}
	philo_st->count = var->nb_philo;
	philo_st->finished = false;
	pthread_mutex_init(&philo_st->msg, NULL);
	philo_st->philos->data = malloc(sizeof(t_philo_data) * philo_st->count);
	while (i < var->nb_philo)
	{
		// philo_st->philos[i].data = malloc(sizeof(t_philo_data));
		philo_st->philos[i].m = &philo_st->msg;
		philo_st->philos[i].d = philo_st;
		philo_st->philos[i].data = var;
		init_data_philo(&philo_st->philos[i], var, i);
		i++;
	}
	return (0);
}

void	philo_create(t_philo_rout *philo)
{
	int	i;

	i = 0;
	while (i < philo->count)
	{
		pthread_create(&philo->threads[i], NULL, philo_routine,
			(void *)&philo->philos[i]);
		i++;
	}
}

void	philo_join(t_philo_rout *philo)
{
	int	i;

	i = 0;
	while (i  < philo->count)
	{
		pthread_join(philo->threads[i], NULL);
		i++;
	}
}
