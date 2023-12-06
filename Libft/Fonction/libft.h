/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturpin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:36:14 by tturpin           #+#    #+#             */
/*   Updated: 2023/11/10 16:34:04 by tturpin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memset(void *c, int val, size_t len);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t len);
void	*ft_memchr(const void *memBlock, int searchedChar, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
int		ft_memcmp(const void *p1, const void *p2, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_strchr(const char *str, int searched);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_strnstr(const char *src, const char *to_find, size_t max);
char	*ft_strrchr(const char *str, int searched);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *src, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);

#endif
