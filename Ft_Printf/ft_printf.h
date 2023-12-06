/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:20:11 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/22 15:06:23 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./Libft/libft.h"

int	print_char(int c);
int	print_string(char *str);
int	print_unsigned(unsigned int nb);
int	print_int(int n);
int	print_hexa_low(unsigned int n);
int	print_hexa_up(unsigned int n);
int	print_pointers(unsigned long n);
int	print_percent(void);
int	ft_printf(const char *str, ...);

#endif
