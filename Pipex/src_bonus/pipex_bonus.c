/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:12:32 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/16 13:32:34 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init2(t_pipex *pipex, char **argv, int argc)
{
	pipex->infile = open(argv[1], O_RDONLY, 0644);
	if (pipex->infile < 0)
		msg_error("Infile");
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		msg_error("Outfile");
}

void	init3(t_pipex *pipex, char **argv, int argc)
{
	if (argc < 6)
		msg("Not enough arguments");
	pipex->infile = open("tmp_here_doc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile < 0)
		msg_error("Infile");
	pipex->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->outfile < 0)
		msg_error("Outfile");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		msg("Not enough arguments");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		init3(&pipex, argv, argc);
		pipex.nb = 3;
		here_doc(argv[2]);
		multi_child(argc, argv, envp, &pipex);

	}
	else
	{
		init2(&pipex, argv, argc);
		pipex.nb = 2;
		multi_child(argc, argv, envp, &pipex);
	}
	return (0);
}
