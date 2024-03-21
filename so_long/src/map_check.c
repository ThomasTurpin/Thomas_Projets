/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:05 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/21 15:04:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void	check_rows(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (j++ < game->map.columns)
// 		if (game->map.full[i][j] != WALL)
// 			msg_error("The map must be surrounded by a wall1", game);
// 	while (i < game->map.rows)
// 	{
// 		if (game->map.full[i][0] != WALL)
// 		{
// 			msg_error("Map invalid. the map must be surrounded by a wall1",
// 				game);
// 		}
// 		else if (game->map.full[i][game->map.columns] != WALL)
// 		{
// 			msg_error("Map invalid. the map must be surrounded by a wall2",
// 				game);
// 		}
// 		i++;
// 	}
// }

// static void	check_columns(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map.columns)
// 	{
// 		if (game->map.full[0][i] != WALL)
// 		{
// 			msg_error("Map invalid. the map must be surrounded by a wal3l",
// 				game);
// 		}
// 		else if (game->map.full[game->map.columns - 1][i] != WALL)
// 		{
// 			msg_error("Map invalid. the map must be surrounded by a wall4",
// 				game);
// 		}
// 		i++;
// 	}
// }

void	check_nb_content(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CP01", game->map.full[y][x]))
				msg_error("Invalid Map. Not expected map parameter.", game);
			if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player_pos.x = x;
				game->map.player_pos.y = y;
				ft_printf("%d\n", game->map.player_pos.x);
				ft_printf("%d\n", game->map.player_pos.y);
			}
			else if (game->map.full[y][x] == COLLECT)
				game->map.collectible++;
			x++;
		}
		y++;
	}
	ft_printf("%d\n", game->map.player_pos.x);
	ft_printf("%d\n", game->map.player_pos.y);
}

void	check_content(t_game *game)
{
	if (game->map.collectible == 0)
		msg_error("Invalid Map. There are no Coins!", game);
	// else if (game->map.exit == 0)
	// 	ft_error_msg("Invalid Map. There is no Exit.", game);
	else if (game->map.players != 1)
		msg_error("Invalid Map. Invalid Player quantity", game);
}

void	ft_check_map(t_game *game)
{
	// check_rows(game);
	// check_columns(game);
	check_nb_content(game);
	// check_content(game);
}
