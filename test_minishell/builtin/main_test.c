/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:29:47 by tturpin           #+#    #+#             */
/*   Updated: 2024/07/02 07:58:30 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	if (ft_strcmp(argv[1], "env") == 0)
		env_cmd(env);
	else if (ft_strcmp(argv[1], "pwd") == 0)
		pwd_no_arg();
	else if (ft_strcmp (argv[1], ""))
	return (0);
}
