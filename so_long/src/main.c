/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:59:28 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/12 14:22:23 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdlib.h>

#define ESC_KEY 53

typedef struct s_sprite
{
	int		x;
	int		y;
	void	*image;
}			t_sprite;

int	close_win(int keycode)
{
	if (keycode)
		exit(0);
	return (0);
}

void	draw_sprite(void *mlx_ptr, void *win_ptr, t_sprite *sprite)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, sprite->image, sprite->x,
		sprite->y);
}

int	main(void)
{
	t_vars	vars;
	char	*wall_path;
	char	*ground_path;
	void	*img;
	void	*img2;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	wall_path = "./Sprite/wall2.xpm";
	ground_path = "./Sprite/Ground.xpm";
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "Windows");
	width = 50;
	height = 50;
	img2 = mlx_xpm_file_to_image(vars.mlx, ground_path, &width, &height);
	img = mlx_xpm_file_to_image(vars.mlx, wall_path, &width, &height);
	while (j < 600)
	{
		i = 0;
		mlx_put_image_to_window(vars.mlx, vars.win, img, i, j);
		i = 50;
		while (i < 600)
		{
			mlx_put_image_to_window(vars.mlx, vars.win, img2, i, j);
			i += 50;
		}
		j+= 50;
	}
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
