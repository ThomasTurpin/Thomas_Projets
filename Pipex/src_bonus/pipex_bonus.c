/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:12:32 by tturpin           #+#    #+#             */
/*   Updated: 2024/04/30 13:41:38 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipexb	pipexb;

	init_params(&pipexb, argc, argv);
	pipexb.pipe = malloc(2 * (sizeof(int) * pipexb.nb_cmd));
	pipexb.paths = find_path(&pipexb, envp);
	pipexb.cmd_path = ft_split(pipexb.paths, ':');
}
