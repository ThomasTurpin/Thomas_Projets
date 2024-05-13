/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:15:31 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/13 08:55:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init(t_pipex *pipex, char **argv, int argc)
{
	if (argc != 5)
		msg("Not the right amount of arguments !");
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		msg_error("Infile");
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 6444);
	if (pipex->outfile < 0)
		msg_error("Outfile");
	if (pipe(pipex->pipe) < 0)
		msg_error("Pipe");
}
