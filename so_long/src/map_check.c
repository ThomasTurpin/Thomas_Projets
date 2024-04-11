/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:05 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/11 11:31:54 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_rows(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(game->map.full[0]) == game->map.rows)
		msg_error("The must be rectangular", game);
	while (j < game->map.columns)
	{
		if (game->map.full[i][j] != WALL)
			msg_error("Map must be surrended by wall", game);
		j++;
	}
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			msg_error("Map must be surrended by wall", game);
		else if (game->map.full[i][j - 1] != WALL)
			msg_error("Map must be surrended by wall", game);
		i++;
	}
}

static void	check_columns(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			msg_error("Map must be surrended by wall", game);
		i++;
	}
	while (j < game->map.columns)
	{
		if (game->map.full[0][j] != WALL)
			msg_error("Map must be surrended by wall", game);
		else if (game->map.full[i - 1][j] != WALL)
			msg_error("Map must be surrended by wall", game);
		j++;
	}
}

void	check_nb_content(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				msg_error("Invalid Map. Not expected map parameter.", game);
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player_pos.x = x;
				game->map.player_pos.y = y;
			}
			else if (game->map.full[y][x] == COLLECT)
				game->map.collectible++;
			else if (game->map.full[y][x] == EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	check_content(t_game *game)
{
	if (game->map.collectible == 0)
		msg_error("Invalid Map. There are no Coins!", game);
	else if (game->map.exit != 1)
		msg_error("Invalid Map. Not the right amount of Exit.", game);
	else if (game->map.players != 1)
		msg_error("Invalid Map. Invalid Player quantity", game);
}

void	ft_check_map(t_game *game)
{
	check_line(game);
	check_columns(game);
	check_rows(game);
	check_nb_content(game);
	check_content(game);
}
