/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:15:31 by tturpin           #+#    #+#             */
/*   Updated: 2024/06/03 13:41:19 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init(t_pipex *pipex, char **argv, int argc)
{
	if (argc != 5)
		msg("Not the right amount of arguments !", 1);
	if (access(argv[1], R_OK) == -1)
		msg_error("");
	pipex->infile = open(argv[1], O_RDONLY, 0644);
	if (pipex->infile < 0)
		msg_error("");
	pipex->outfile = 1;
	if (pipe(pipex->pipe) < 0)
		msg_error("");
}
