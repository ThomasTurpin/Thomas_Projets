/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:25:47 by tturpin           #+#    #+#             */
/*   Updated: 2024/06/06 13:00:21 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	init(&pipex, argv, argc);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		msg("", 1);
	if (pipex.pid1 == 0)
		first_child(envp, pipex, argv);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		msg("", 1);
	if (pipex.pid2 == 0)
		second_child(envp, pipex, argv);
	close_pipe(&pipex);
	while (waitpid(0, &pipex.status, 2) != -1)
		continue ;
	status = WEXITSTATUS(pipex.status);
	free_main(&pipex);
	return (status);
}
