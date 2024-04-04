/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:42 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/04 14:01:07 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	msg_error(char *message, t_game *game)
{
	if (game->alloc == true)
		free_map(game);
	free(game);
	ft_printf("Error\n");
	ft_printf("%s", message);
	exit(1);
}

void	free_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.rows)
	{
		free(game->map.full[i]);
		i++;
	}
	free(game->map.full);
}

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.xpm);
	mlx_destroy_image(game->mlx, game->ground.xpm);
	mlx_destroy_image(game->mlx, game->player_sprite.xpm);
	mlx_destroy_image(game->mlx, game->exit_cl.xpm);
	mlx_destroy_image(game->mlx, game->exit_op.xpm);
	mlx_destroy_image(game->mlx, game->collect.xpm);
}

void	free_all(t_game *game)
{
	destroy_image(game);
	free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

int	close_win(t_game *game)
{
	free_all(game);
	ft_printf("CLOSED\n");
	exit (1);
}
