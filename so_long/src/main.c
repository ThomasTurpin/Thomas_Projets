/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:59:28 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/20 16:08:09 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_win(int keycode)
{
	if (keycode)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc (sizeof(t_game));
	check_argv(argc, argv, game);
	init_map(game, argv[1]);
	param_init(game);
	// ft_check_map(game);
	ft_mlx_init(game);
	init_sprite(game);
	rendering_map(game);
	mlx_loop(game->mlx);
	return (0);
}
