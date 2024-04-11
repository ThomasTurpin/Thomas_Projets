/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:53:13 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/11 11:32:43 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strappend(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	victory(t_game *game)
{
	free_all(game);
	ft_printf("VICTORY\n");
	exit(1);
}

void	print_mouvements(t_game *game)
{
	char	*mouv;
	char	*phrase;

	mouv = ft_itoa(game->moove);
	phrase = ft_strjoin("Mouvements :", mouv);
	ft_printf("%s\n", phrase);
	free(mouv);
	free(phrase);
}

int	is_valid(size_t row, size_t col, t_game *game)
{
	if (game->map.full[row][col] != WALL)
		return (1);
	else
		return (0);
}

void	check_line(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	while (game->map.full[i][j])
		j++;
	i = 1;
	while (game->map.full[i])
	{
		count = 0;
		while (game->map.full[i][count])
			count++;
		if (count != j)
			msg_error("all line have not the same size.", game);
		i++;
	}
}
