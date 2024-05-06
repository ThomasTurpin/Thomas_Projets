/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:26:00 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/06 15:11:50 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		outfile;
	int		infile;
	int		pipe[2];
	char	*paths;
	char	**cmd_path;
	char	**cmd_args;
	char	*cmd;
}			t_pipex;

void		msg(char *msg);
void		msg_error(char *error);
void		init(t_pipex *pipex, char **argv, int argc);
void		close_pipe(t_pipex *pipex);
char		*find_path(char *cmd, char **envp);
void		first_child(char **envp, t_pipex pipex, char **argv);
void		second_child(char **envp, t_pipex pipex, char **argv);
void		free_main(t_pipex *pipex);
void		free_child(t_pipex *pipex);
void		free_split(char **split);
void		free_path(char *path);
void		free_path2(char *path, char **split);
void		exec_cmd(char **envp, char *argv);

#endif
