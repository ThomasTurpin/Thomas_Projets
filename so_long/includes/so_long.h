/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:59:32 by tturpin           #+#    #+#             */
/*   Updated: 2024/03/20 16:11:05 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_HEIGHT 50
# define IMG_WIDTH 50

# define WALL '1'
# define GROUND '0'
# define COLLECT 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define WALL_XPM "../Sprite/wall2.xpm"
# define GROUND_XPM "../Sprite/Ground.xpm"
# define COLLECTABLE_XPM "../Sprite/collectable.xpm"

typedef struct s_sprite
{
	void		*xpm;
	int			x;
	int			y;
}				t_sprite;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			collectible;
	int			exit;
	int			player;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			moove;
	t_map		map;
	bool		alloc;
	t_sprite	wall;
	t_sprite	ground;
	t_sprite	collect;
	t_sprite	exit_op;
	t_sprite	exit_cl;
	t_sprite	player_sprite;
}				t_game;

void			check_argv(int argc, char **argv, t_game *game);
void			msg_error(char *message, t_game *game);
void			free_map(t_game *game);
char			*ft_strappend(char **s1, const char *s2);
void			init_map(t_game *game, char *argv);
void			ft_check_for_empty_line(char *map, t_game *game);
void			param_init(t_game *game);
void			ft_check_map(t_game *game);
void			ft_mlx_init(t_game *game);

t_sprite		ft_new_sprite(void *mlx, char *path, t_game *game);
void			init_sprite(t_game *game);
void			put_sprite(t_game *game, t_sprite sprite, int line, int column);
void			which_sprite(t_game *game, int y, int x);
int				rendering_map(t_game *game);

#endif
