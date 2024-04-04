/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:53:13 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/04 11:17:13 by tturpin          ###   ########.fr       */
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
