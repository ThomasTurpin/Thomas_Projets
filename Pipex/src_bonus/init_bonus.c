/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:46:32 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/30 13:37:04 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

void	init_params(t_pipexb *pipexb, int argc, char **argv)
{
	pipexb->nb_cmd = argc - 3;
	pipexb->nb_pipe = pipexb->nb_cmd - 1;
		pipexb->infile = open(argv[1], O_RDONLY);
	if (pipexb->infile < 0)
		msg_error("Infile");
	pipexb->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipexb->outfile < 0)
		msg_error("Outfile");
}
