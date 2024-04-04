/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:12:56 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/04 11:16:56 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid(size_t row, size_t col, t_game *game)
{
	if (game->map.full[row][col] != WALL)
		return (1);
	else
		return (0);
}

void	exit_coins(size_t x, size_t y, t_game *game)
{
	if (game->path.tmp_map[x][y] == COLLECT)
		game->path.saw_collect += 1;
	else if (game->path.tmp_map[x][y] == EXIT)
		game->path.saw_exit += 1;
}



void	path_check(size_t row, size_t col, t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	game->path.tmp_map[row][col] = WALL;
	while (i < 4)
	{
		if (i == 0)
		{
			x = row;
			y = col + 1;
		}
		else if (i == 1)
		{
			x = row;
			y = col -1;
		}
		else if (i == 2)
		{
			x = row + 1;
			y = col;
		}
		else
		{
			x = row -1;
			y = col;
		}
		i++;
		exit_coins(x, y, game);
		if (is_valid(x, y, game))
			path_check(x, y, game);
	}
}

void	init_path(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	game->path.tmp_map = game->map.full;
	while (i < game->map.rows && game->map.full[i][j] != PLAYER)
	{
		j++;
		if (j >= game->map.columns)
		{
			j = 0;
			i++;
		}
	}
	path_check(i, j, game);
}

void	path(t_game *game)
{
	init_path(game);
	if (game->path.saw_collect != game->map.collectible)
		msg_error("All the collectable are not reacheable", game);
	else if (game->path.saw_exit != game->map.exit)
		msg_error("The exit is not recheable", game);
}

