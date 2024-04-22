/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:25:47 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/22 11:57:18 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

// int	main(void)
// {
// 	int fd;
// 	char	*args[3];

// 	args[0] = "ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	printf("This is printed in example.txt!\n");
// 	if (access("example.txt", R_OK) != -1)
// 		printf("I have the permission to read");
// 	else
// 		printf("Don't have the permission !");
// 	unlink("example.txt");
// 	execve("/bin/ls", args, NULL);
// 	return (0);
// }

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
	// unlink(argv[argc - 1]);
}
