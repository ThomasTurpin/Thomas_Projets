/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:12:56 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/11 08:31:54 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_coins(size_t x, size_t y, t_game *game)
{
	if (game->path.tmp_map[x][y] == COLLECT)
	{
		game->path.saw_collect += 1;
		return (1);
	}
	else if (game->path.tmp_map[x][y] == EXIT && game->path.saw_exit < 1)
	{
		game->path.saw_exit += 1;
		return (0);
	}
	return (1);
}

void	coordonate(int i, size_t row, size_t col, t_game *game)
{
	if (i == 0)
	{
		game->path.x = row;
		game->path.y = col + 1;
	}
	else if (i == 1)
	{
		game->path.x = row;
		game->path.y = col - 1;
	}
	else if (i == 2)
	{
		game->path.x = row + 1;
		game->path.y = col;
	}
	else
	{
		game->path.x = row - 1;
		game->path.y = col;
	}
}

void	path_check(size_t row, size_t col, t_game *game)
{
	int	i;

	i = 0;
	if (game->path.tmp_map[row][col] != EXIT)
		game->path.tmp_map[row][col] = WALL;
	while (i < 4)
	{
		coordonate(i, row, col, game);
		if (exit_coins(game->path.x, game->path.y, game) == 0)
			break ;
		i++;
		if (is_valid(game->path.x, game->path.y, game))
			path_check(game->path.x, game->path.y, game);
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

void	path(t_game *game, char *argv)
{
	(void)argv;
	init_path(game);
	if (game->path.saw_collect != game->map.collectible)
		msg_error("All the collectable are not reacheable", game);
	else if (game->path.saw_exit != game->map.exit)
		msg_error("The exit is not recheable", game);
	free_map(game);
	init_map(game, argv);
}
