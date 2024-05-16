/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:52:34 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/16 13:32:01 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	new_get_next_line(char **line)
{
	char	*buff;
	int		i;
	int		r;
	char	l;

	i = 0;
	r = 0;
	buff = (char *)ft_calloc(10000, 1);
	if (!buff)
		return (-1);
	r = read(0, &l, 1);
	while (r && l != '\n' && l != '\0')
	{
		if (l != '\n' && l != '\0')
			buff[i] = l;
		i++;
		r = read(0, &l, 1);
	}
	buff[++i] = '\0';
	*line = buff;
	return (r);
}

void	here_doc(char *limiter)
{
	pid_t	herepid;
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		msg_error("Error ");
	herepid = fork();
	if (herepid == 0)
	{
		close(fd[0]);
		while (new_get_next_line(&line))
		{
			if (ft_strcmp(line, limiter) == 0)
				exit(0);
			free(line);
		}
		exit(1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(herepid, NULL, 0);
	}
}
