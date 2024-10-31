/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:24:23 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/31 15:04:29 by tturpin          ###   ########.fr       */
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

typedef struct s_philo_var
{
	int					nb_philo;
	long long			timetodie;
	long long			timetoeat;
	long long			timetosleep;
	int					meallimit;
	long long			time_starting;
}						t_philo_var;

typedef struct s_philo_data
{
	t_philo_var			*data;
	int					id;
	long long			die_time;
	t_mutex				left_f;
	t_mutex				*right_f;
	t_mutex				*first_fork;
	t_mutex				*second_fork;
	t_mutex				*m;
	int					times_eaten;
	bool				died;
	struct s_philo_rout	*d;
}						t_philo_data;

typedef struct s_philo_rout
{
	int					is_dead;
	t_philo_data		*philos;
	pthread_t			*threads;
	t_mutex				msg;
	int					count;
}						t_philo_rout;

/*INIT VAR*/

int						ft_atoi(const char *str, int *n);
int						ft_atoll(const char *str, long long *n);
int						init_var(int argc, char **argv, t_philo_var *var);

/*INIT PHILO*/
int						init_philo(t_philo_rout *philo_st, t_philo_var *var);
void					init_data_philo(t_philo_data *philo, t_philo_var *var,
							int i);
void					philo_create(t_philo_rout *philo);
void					philo_join(t_philo_rout *philo);

/*DINNER*/
int						ft_dinner(t_philo_data *philo);
void					*philo_routine(void *data);
void					ft_eat(t_philo_data *philo);
void					ft_think(t_philo_data *philo);
void					ft_sleep(t_philo_data *philo);
void					ft_die(t_philo_data *philo);

/*TIME*/
long long				ft_get_time(void);
void					u_wait(long long waiting_time);

/*UTILS*/
int						ft_strcmp(const char *s1, const char *s2);
void					ft_msg(t_philo_data *philo, int id,
							const char *actions);
void					free_all(t_philo_rout *philo);

#endif
