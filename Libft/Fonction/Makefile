# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturpin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 09:49:55 by tturpin           #+#    #+#              #
#    Updated: 2023/11/10 16:34:55 by tturpin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_memcpy.c ft_memset.c ft_strlen.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_strjoin.c
ADD = ft_substr.c ft_split.c ft_strtrim.c
SRCS = ${LIBC} ${ADD}
OBJS = ${SRCS:.c=.o}

${LIB}: ${OBJS}
	ar -rsc ${LIB} ${OBJS}
all: ${LIB}

clean:
	rm -f ${OBJS}

fclean: clean;
	rm -f ${LIB}

re: fclean all
.PHONY: all clean fclean re
