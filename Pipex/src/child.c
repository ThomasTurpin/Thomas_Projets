/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:52:24 by tturpin           #+#    #+#             */
/*   Updated: 2024/06/03 13:48:58 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	exec_cmd(char **envp, char *argv)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd[0])
	{
		free_split(cmd);
		msg("Command not found", 127);
	}
	if (access(cmd[0], F_OK) == 0)
	{
		path = ft_strdup(cmd[0]);
		if (!path)
			free_path(path);
	}
	else
	{
		path = find_path(cmd[0], envp);
		if (!path)
			free_path2(path, cmd);
	}
	if (execve(path, cmd, envp) == -1)
		free_path2(path, cmd);
}

void	first_child(char **envp, t_pipex pipex, char **argv)
{
	if (access(argv[1], R_OK) == -1)
	{
		close(pipex.pipe[0]);
		close(pipex.pipe[1]);
		msg("", 1);
	}
	dup2(pipex.infile, 0);
	close(pipex.infile);
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[1]);
	close(pipex.pipe[0]);
	exec_cmd(envp, argv[2]);
}

void	second_child(char **envp, t_pipex pipex, char **argv)
{
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pipex.outfile < 0)
		msg_error("");
	if (access(argv[4], W_OK) == -1)
	{
		close(pipex.pipe[0]);
		close(pipex.infile);
		close(pipex.pipe[1]);
		close(pipex.outfile);
		msg("", 1);
	}
	dup2(pipex.pipe[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.outfile);
	close(pipex.pipe[0]);
	close(pipex.infile);
	close(pipex.pipe[1]);
	exec_cmd(envp, argv[3]);
}
