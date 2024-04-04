/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:09 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/04 14:00:29 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_argv(int argc, char **argv, t_game *game)
{
	size_t	map_len;

	if (argc > 2)
		msg_error("Too many arguments", game);
	if (argc < 2)
		msg_error("Map file is missing", game);
	map_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
		msg_error("Map extension is wrong (.ber)", game);
}

void	init_map(t_game *game, char *argv)
{
	char	*tmp;
	char	*tmp_line;
	size_t	fd_map;

	fd_map = open(argv, O_RDONLY);
	if ((int)fd_map == -1)
		msg_error("Can't open the map", game);
	tmp = ft_strdup("");
	game->map.rows = 0;
	while (1)
	{
		tmp_line = get_next_line(fd_map);
		if (tmp_line == NULL)
			break ;
		tmp = ft_strappend(&tmp, tmp_line);
		free(tmp_line);
		game->map.rows++;
	}
	close(fd_map);
	ft_check_for_empty_line(tmp, game);
	game->map.full = ft_split(tmp, '\n');
	game->alloc = true;
	free(tmp);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	size_t	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		msg_error("Invalid map1", game);
	}
	else if (map[ft_strlen(map)] == '\n')
	{
		free(map);
		msg_error("Invalid map2", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			msg_error("Invalid map3.", game);
		}
		i++;
	}
}
