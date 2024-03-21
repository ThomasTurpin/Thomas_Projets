/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:08:21 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/21 15:40:09 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int keycode, t_game *game)
{
	if (keycode == W)
		player_moove(game, game->map.player_pos.y - 1, game->map.player_pos.x);
	if (keycode == A)
		player_moove(game, game->map.player_pos.y, game->map.player_pos.x - 1);
	if (keycode == D)
		player_moove(game, game->map.player_pos.y, game->map.player_pos.x + 1);
	if (keycode == S)
		player_moove(game, game->map.player_pos.y + 1, game->map.player_pos.x);
	if (keycode == ESC)
		close_win(keycode);
	return (0);
}

void	player_moove(t_game *game, int new_y, int new_x)
{
	int	save_x;
	int	save_y;

	save_x = game->map.player_pos.x;
	save_y = game->map.player_pos.y;
	if (game->map.full[new_y][new_x] == GROUND
		|| game->map.full[new_y][new_x] == COLLECT)
	{
		game->map.full[save_y][save_x] = GROUND;
		game->map.player_pos.x = new_x;
		game->map.player_pos.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
	}
	rendering_map(game);
}
