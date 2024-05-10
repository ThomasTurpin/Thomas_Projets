/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:52:24 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/10 08:11:50 by tturpin          ###   ########.fr       */
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
		msg("Command not found");
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
	if (access(path, F_OK) == -1)
		msg("Error");
	if (execve(path, cmd, envp) == -1)
		free_path(path);
}

void	first_child(char **envp, t_pipex pipex, char **argv)
{
	dup2(pipex.pipe[1], 1);
	dup2(pipex.infile, 0);
	close(pipex.pipe[0]);
	exec_cmd(envp, argv[2]);
}

void	second_child(char **envp, t_pipex pipex, char **argv)
{
	dup2(pipex.pipe[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.pipe[1]);
	exec_cmd(envp, argv[3]);
}
