/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:36:14 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/07 09:45:00 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

void    *ft_memcpy(void *dest, const void *src, size_t size);
void    *memset(void *c, int val, size_t len);
int     ft_isalpha(int c);
int     ft_isalnum(int c);
int     ft_isdigit(int c);
int     ft_isprint(int c);
int     ft_isascii(int c);
int     ft_strlen(char *str);
void    ft_bzero(void *s, size_t len);

#endif
