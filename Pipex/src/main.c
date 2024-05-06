/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:25:47 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/30 15:37:04 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	pipex;

	init(&pipex, argv, argc);
	pipex.paths = find_path(&pipex, envp);
	pipex.cmd_path = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(envp, pipex, argv);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(envp, pipex, argv);
	close_pipe(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_main(&pipex);
}
