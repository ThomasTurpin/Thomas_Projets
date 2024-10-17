/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:15:53 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/07 14:00:25 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*malloc_handle(size_t nb)
{
	void	*mall;

	mall = malloc(nb);
	if (mall == NULL)
		error_msg("Erorr with malloc");
	return (mall);
}

void	mutex_handle(t_mutex *mutex, const char *code)
{
	if (ft_strcmp(code, "lock"))
		pthread_mutex_lock(mutex);
	else if (ft_strcmp(code, "unlock"))
		pthread_mutex_unlock(mutex);
	else if (ft_strcmp(code, "init"))
		pthread_mutex_init(mutex, NULL);
	else if (ft_strcmp(code, "destroy"))
		pthread_mutex_destroy(mutex);
	else
		error_msg("Not a valid number for mutex");
}

void	handle_thread(pthread_t *thread, void *(*foo)(void *), void *data,
		const char *code)
{
	if (ft_strcmp(code, "create"))
		pthread_create(thread, NULL, foo, data);
	else if (ft_strcmp(code, "join"))
		pthread_join(*thread, NULL);
	else if (ft_strcmp(code, "detach"))
		pthread_detach(*thread);
	else
		error_msg("Wrong code for threads");
}
