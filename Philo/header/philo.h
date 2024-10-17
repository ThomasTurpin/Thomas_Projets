/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 08:25:37 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/17 13:37:43 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	long				last_time_eat;
	int					time_eaten;
	int					philo_full;
	long				die_time;
	t_mutex				*left_f;
	t_mutex				*right_f;
	pthread_t			*thread;
	t_data				*data;
}						t_philo;

struct					s_data
{
	long				nb_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nb_meal;
	long				start;
	int					is_dead;
	t_philo				*philo;
};

void					error_msg(const char *msg);
void					check_input(t_data *data, char **argv);
void					init_data(t_philo *philo);

void					*malloc_handle(size_t nb);
void					mutex_handle(t_mutex *mutex, const char *code);
void					handle_thread(pthread_t *thread, void *(*foo)(void *),
							void *data, const char *code);
int						ft_strcmp(const char *s1, const char *s2);
void					philo_create(t_philo *philo);
void					philo_join(t_philo *philo);
void					*philo_routine(void *data);
void					one_philo(t_philo *philo);

void					ft_think(t_philo *philo);
void					ft_sleep(t_philo *philo);
void					ft_die(t_philo *philo);
void					ft_eat(t_philo *philo);

void					end_free(t_philo *philo);
void					ft_print(t_philo *philo, const char *msg);
long long				ft_get_time(void);

#endif
