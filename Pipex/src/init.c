/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:15:31 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/23 16:38:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init(t_pipex *pipex, char **argv, int argc)
{
	if (argc != 5)
		msg("Not the right amount of arguments !", 1);
	if (access(argv[1], R_OK) == -1)
		msg_error("Infile");
	pipex->infile = open(argv[1], O_RDONLY, 0644);
	if (pipex->infile < 0)
		msg_error("Infile");
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		msg_error("Outfile");
	if (access(argv[argc - 1], W_OK) != 0)
		msg_error("Outfile");
	if (pipe(pipex->pipe) < 0)
		msg_error("Pipe");
}
