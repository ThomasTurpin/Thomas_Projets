/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:26:00 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/16 13:32:08 by tturpin          ###   ########.fr       */
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
	pid_t	pid;
	pid_t	here;
	int		outfile;
	int		infile;
	int		pipe[2];
	int		nb;
}			t_pipex;

void		msg(char *msg);
void		msg_error(char *error);
void		init(t_pipex *pipex, char **argv, int argc);
void		close_pipe(t_pipex *pipex);
char		*find_path(char *cmd, char **envp);
void		first_child(char **envp, t_pipex pipex, char **argv);
void		second_child(char **envp, t_pipex pipex, char **argv);
void		free_main(t_pipex *pipex);
void		free_split(char **split);
void		free_path(char *path);
void		free_path2(char *path, char **split);
void		exec_cmd(char **envp, char *argv);

void		init3(t_pipex *pipex, char **argv, int argc);
void		init2(t_pipex *pipex, char **argv, int argc);
void		multi_child(int argc, char **argv, char **envp, t_pipex *pipex);
void		choose_child(int argc, char **argv, t_pipex *pipex, char **envp);
void		child1(char *argv, char **envp, t_pipex *pipex);
void		child(char *argv, char **envp, t_pipex *pipex);
void		here_doc(char *limiter);
int			ft_strcmp(char *s1, char *s2);
int			new_get_next_line(char **line);
void		child2(char *argv, char **envp, t_pipex *pipex);

#endif
