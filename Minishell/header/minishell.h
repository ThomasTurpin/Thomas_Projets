/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:41:34 by tturpin           #+#    #+#             */
/*   Updated: 2024/11/26 14:48:19 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cmd
{
	char			**cmd;/*cmd[0] = commande et cmd[1 ou plus] = arguments*/
	int				fd_input;
	int				fd_output;
	bool			pipe;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

#endif
