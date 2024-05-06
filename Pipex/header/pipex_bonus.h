/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:50:03 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/30 13:23:39 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipexb
{
	pid_t	pid;
	int		infile;
	int		outfile;
	int		*pipe;
	char	*paths;
	char	**cmd_path;
	char	**cmd_args;
	char	*cmd;
	int		nb_cmd;
	int		nb_pipe;
	int		here_doc;
}			t_pipexb;

void	init_params(t_pipexb *pipexb, int argc, char **argv);
void	msg_error(char *error);
char	*find_path(t_pipexb *pipexb, char **envp);

#endif
