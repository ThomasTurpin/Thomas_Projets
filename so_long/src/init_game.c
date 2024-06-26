/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:17:06 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/11 11:36:11 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	param_init(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.full[i])
	{
		i++;
	}
	game->map.rows = i;
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->moove = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->path.saw_collect = 0;
	game->path.saw_exit = 0;
	game->alloc = true;
	game->map.player_pos.x = 0;
	game->map.player_pos.y = 0;
}

void	ft_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free(game->mlx);
		msg_error("Error with the mlx pointer.", game);
	}
	game->win = mlx_new_window(game->mlx, game->map.columns * IMG_WIDTH,
			game->map.rows * IMG_HEIGHT, "So_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		msg_error("Cant't create the windows", game);
	}
}

t_sprite	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_sprite	sprite;

	sprite.xpm = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm == NULL)
	{
		msg_error("Sprite not find.", game);
	}
	return (sprite);
}

void	init_sprite(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->ground = ft_new_sprite(mlx, GROUND_XPM, game);
	game->wall = ft_new_sprite(mlx, WALL_XPM, game);
	game->collect = ft_new_sprite(mlx, COLLECTABLE_XPM, game);
	game->player_sprite = ft_new_sprite(mlx, PLAYER_XPM, game);
	game->exit_cl = ft_new_sprite (mlx, EXIT_CLOSE_XPM, game);
	game->exit_op = ft_new_sprite (mlx, EXIT_OPEN_XPM, game);
}
