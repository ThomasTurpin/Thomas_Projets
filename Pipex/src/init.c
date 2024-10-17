/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:15:31 by tturpin           #+#    #+#             */
/*   Updated: 2024/07/02 12:53:53 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init(t_pipex *pipex, char **argv, int argc)
{
	if (argc != 5)
		msg("Not the right amount of arguments !", 1);
	pipex->infile = open(argv[1], O_RDONLY, 0644);
	pipex->outfile = -1;
	pipex->outfile_err = 0;
	if (pipe(pipex->pipe) < 0)
		msg_error("");
}
