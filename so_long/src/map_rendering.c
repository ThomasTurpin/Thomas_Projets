/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:49:00 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/28 07:46:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_sprite(t_game *game, t_sprite sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm, column * sprite.x,
		line * sprite.y);
}

void	which_sprite(t_game *game, int y, int x)
{
	char	map_full;

	map_full = game->map.full[y][x];
	if (map_full == WALL)
		put_sprite(game, game->wall, y, x);
	if (map_full == GROUND)
		put_sprite(game, game->ground, y, x);
	if (map_full == COLLECT)
		put_sprite(game, game->collect, y, x);
	if (map_full == PLAYER)
		put_sprite(game, game->player_sprite, y, x);
	if (map_full == EXIT)
	{
		if (game->map.collectible == 0)
			put_sprite(game, game->exit_op, y, x);
		else
			put_sprite(game, game->exit_cl, y, x);
	}
}

int	rendering_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			which_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
