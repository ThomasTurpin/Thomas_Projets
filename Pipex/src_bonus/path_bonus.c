/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:14:03 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/30 13:41:54 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

char	*find_path(t_pipexb *pipexb, char **envp)
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
		close(pipexb->infile);
		close(pipexb->outfile);
		// close_pipe(pipexb);
	}
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);

}
