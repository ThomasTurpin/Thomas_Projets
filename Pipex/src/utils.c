/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 09:02:23 by tturpin           #+#    #+#             */
/*   Updated: 2024/05/16 12:52:32 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split[i]);
		free (split);
	}

}

void	free_path(char *path)
{
	free(path);
	msg_error("Error1");
}

void	free_path2(char *path, char **split)
{
	free(path);
	free_split(split);
	msg("Command not found");
}
