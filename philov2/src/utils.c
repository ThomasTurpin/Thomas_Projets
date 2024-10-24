/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:25:59 by tturpin           #+#    #+#             */
/*   Updated: 2024/10/24 08:34:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static int	check_max_ll(int neg, long long *n)
{
	if (!neg && *n == LLONG_MIN)
		return (2);
	if (*n < 0 && *n != LLONG_MIN)
		return (2);
	return (0);
}

static int	check_max_int(int neg, int *n)
{
	if (!neg && *n == INT_MIN)
		return (2);
	if (*n < 0 && *n != INT_MIN)
		return (2);
	return (0);
}

int	ft_atoi(const char *str, int *n)
{
	int	neg;

	*n = 0;
	neg = 0;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str && *str >= '0' && *str <= '9')
	{
		*n = (*n * 10) + *str - 48;
		if (check_max_int(neg, n))
			return (2);
		str++;
	}
	if (neg)
		*n *= -1;
	if (*str == '\0')
		return (0);
	return (1);
}

int	ft_atoll(const char *str, long long *n)
{
	int	neg;

	*n = 0;
	neg = 0;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || *str == '-')
		str++;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str && *str >= '0' && *str <= '9')
	{
		*n = (*n * 10) + *str - 48;
		if (check_max_ll(neg, n))
			return (2);
		str++;
	}
	if (*str == '\0')
		return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

