/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:59:28 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/08 15:01:44 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_argv(argc, argv, game);
	init_map(game, argv[1]);
	param_init(game);
	ft_check_map(game);
	path(game, argv[1]);
	ft_mlx_init(game);
	init_sprite(game);
	rendering_map(game);
	mlx_hook(game->win, 2, 1L<<0, input, game);
	mlx_hook(game->win, 17, 1L << 3, close_win, game);
	mlx_hook(game->win, 12, 1L<<15, rendering_map, game);
	mlx_loop(game->mlx);
	free_all(game);
	return (0);
}
