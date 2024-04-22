/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:47:13 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/22 11:36:39 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	msg(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	msg_error(char *error)
{
	perror(error);
	exit(1);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	free_main(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_path[i])
	{
		free (pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}

void	free_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free (pipex->cmd_args[i]);
		i++;
	}
	free (pipex->cmd_args);
	free(pipex->cmd);
}
