/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:52:24 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/30 15:41:09 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		ft_printf("%d\n", access(command, X_OK));
		if (access(command, X_OK) == 0)
			return (command);
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		free(command);
		paths++;
	}
	return (NULL);
}

void	exec_env(t_pipex *pipex, char **envp, char **argv)
{

}

void	first_child(char **envp, t_pipex pipex, char **argv)
{
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	ft_printf("%s\n", pipex.cmd_args);
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		free_child(&pipex);
		msg("Erreur cmd");
	}
	exec_cmd(&pipex, envp);
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
	free_child(&pipex);
}
