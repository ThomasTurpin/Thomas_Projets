/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:12:32 by tturpin           #+#    #+#             */
/*   Updated: 2024/07/02 13:12:05 by tturpin          ###   ########.fr       */
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
		msg("Outfile", 1);
}

void	init3(t_pipex *pipex, char **argv, int argc)
{
	if (argc < 6)
		msg("Not enough arguments", 1);
	pipex->outfile = open(argv[argc - 1], O_CREAT | O_APPEND | O_RDWR, 0644);
	if (pipex->outfile < 0)
		msg("Outfile", 1);
}

void	choose_child1(int argc, char **argv, t_pipex *pipex, char **envp)
{
	if (pipex->pid == 0)
	{
		if (pipex->nb == 3)
			child1(argv[pipex->nb], envp, pipex);
		if (pipex->nb == argc - 2)
			child2(argv[pipex->nb], envp, pipex);
		else
			child(argv[pipex->nb], envp, pipex);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	if (argc < 5)
		msg("Not enough arguments", 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		init3(&pipex, argv, argc);
		pipex.nb = 3;
		pipex.here_doc = 1;
		here_doc(argv[2], &pipex);
		multi_child(argc, argv, envp, &pipex);
	}
	else
	{
		init2(&pipex, argv, argc);
		pipex.nb = 2;
		multi_child(argc, argv, envp, &pipex);
	}
	while (waitpid(0, &pipex.status, 2) != -1)
		continue ;
	status = WEXITSTATUS(pipex.status);
	free_main(&pipex);
	return (status);
}
