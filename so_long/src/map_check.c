/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:05 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/19 16:26:40 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_rows(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j++ < game->map.columns)
		if (game->map.full[i][j] != WALL)
			msg_error("The map must be surrounded by a wall1", game);
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
		{
			msg_error("Map invalid. the map must be surrounded by a wall1",
				game);
		}
		else if (game->map.full[i][game->map.columns] != WALL)
		{
			msg_error("Map invalid. the map must be surrounded by a wall2",
				game);
		}
		i++;
	}
}

static void	check_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
		{
			msg_error("Map invalid. the map must be surrounded by a wal3l",
				game);
		}
		else if (game->map.full[game->map.columns - 1][i] != WALL)
		{
			msg_error("Map invalid. the map must be surrounded by a wall4",
				game);
		}
		i++;
	}
}


void	ft_check_map(t_game *game)
{
	check_rows(game);
	check_columns(game);
	// check_nb_content(game);
	// check_content(game);
}
