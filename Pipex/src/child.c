/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:52:24 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/22 11:42:54 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(char **envp, t_pipex pipex, char **argv)
{
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg("Erreur cmd");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void	second_child(char **envp, t_pipex pipex, char **argv)
{
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg("Erreur cmd");
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
