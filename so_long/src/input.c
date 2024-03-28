/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:08:21 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/28 07:46:53 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	input(int keycode, t_game *game)
{
	if (keycode == W)
		player_move(game, game->map.player_pos.y - 1, game->map.player_pos.x);
	if (keycode == A)
		player_move(game, game->map.player_pos.y, game->map.player_pos.x - 1);
	if (keycode == D)
		player_move(game, game->map.player_pos.y, game->map.player_pos.x + 1);
	if (keycode == S)
		player_move(game, game->map.player_pos.y + 1, game->map.player_pos.x);
	if (keycode == ESC)
		close_win(game);
	return (0);
}

void	player_move(t_game *game, int new_y, int new_x)
{
	int	save_x;
	int	save_y;

	save_x = game->map.player_pos.x;
	save_y = game->map.player_pos.y;
	if (game->map.full[new_y][new_x] == EXIT && game->map.collectible == 0)
		victory(game);
	if (game->map.full[new_y][new_x] == GROUND
		|| game->map.full[new_y][new_x] == COLLECT)
	{
		print_mouvements(game);
		if (game->map.full[new_y][new_x] == COLLECT)
			game->map.collectible--;
		game->map.full[save_y][save_x] = GROUND;
		game->map.player_pos.x = new_x;
		game->map.player_pos.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
	}
	game->moove++;
	rendering_map(game);
}
