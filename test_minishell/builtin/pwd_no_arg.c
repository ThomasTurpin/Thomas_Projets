/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_no_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:39:30 by tturpin           #+#    #+#             */
/*   Updated: 2024/06/25 11:42:17 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	pwd_no_arg(void)
{
	char	act_dir[1024];

	getcwd(act_dir, sizeof(act_dir));
	printf("%s\n", act_dir);
	return (0);
}
