/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:08:36 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/22 11:42:42 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	multi_child(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (pipex->nb == 3)
		pipex->unlink = 1;
	while (pipex->nb <= argc - 2)
	{
		if (pipe(pipex->pipe) == -1)
			msg_error("Error ");
		pipex->pid = fork();
		if (pipex->pid == -1)
			msg_error("Error ");
		choose_child(argc, argv, pipex, envp);
		dup2(pipex->pipe[0], 0);
		close(pipex->pipe[0]);
		close(pipex->pipe[1]);
		pipex->nb++;
	}
	while (wait(NULL) != -1)
		continue ;
}

void	choose_child(int argc, char **argv, t_pipex *pipex, char **envp)
{
	if (pipex->pid == 0)
	{
		if (pipex->nb == 2)
			child1(argv[pipex->nb], envp, pipex);
		if (pipex->nb == argc - 2)
			child2(argv[pipex->nb], envp, pipex);
		else
			child(argv[pipex->nb], envp, pipex);
	}
}

void	child1(char *argv, char **envp, t_pipex *pipex)
{
	dup2(pipex->infile, 0);
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	exec_cmd(envp, argv);
}

void	child(char *argv, char **envp, t_pipex *pipex)
{
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	exec_cmd(envp, argv);
}

void	child2(char *argv, char **envp, t_pipex *pipex)
{
	dup2(pipex->outfile, 1);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	exec_cmd(envp, argv);
}
