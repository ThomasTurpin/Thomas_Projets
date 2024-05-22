/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:20:35 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/22 11:41:58 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**tmp_path;
	char	*path;
	char	*tmp;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
	{
		i++;
	}
	if (!envp[i])
		return (NULL);
	tmp_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (tmp_path[i])
	{
		tmp = ft_strjoin(tmp_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (free_split(tmp_path), path);
		free(path);
		i++;
	}
	return (free_split(tmp_path), NULL);
}
