/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:20:35 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/22 10:30:24 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*find_path(t_pipex *pipex, char	**envp)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			error = 1;
		i++;
	}
	if (error == 0)
	{
		close(pipex->infile);
		close(pipex->outfile);
		close_pipe(pipex);
	}
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);

}
