/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:47:13 by tturpin           #+#    #+#             */
/*   Updated: 2024/06/03 13:39:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	msg(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	msg_error(char *error)
{
	perror(error);
}

void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	free_main(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
}
