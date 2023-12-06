# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturpin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 15:19:15 by tturpin           #+#    #+#              #
#    Updated: 2023/12/04 17:47:06 by tturpin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = ./Libft

SRCS = ft_printf.c print_int.c print_char.c print_string.c print_unsigned.c print_pointers.c print_hexa_low.c print_percent.c print_hexa_up.c


OBJS = ${SRCS:.c=.o}

all: ${NAME}
makelibft:
	@make bonus -C ${LIBFTDIR}
	@cp ${LIBFTDIR}/${LIBFTNAME} .
	@mv ${LIBFTNAME} ${NAME}

${NAME}: makelibft ${OBJS}
	@ar -r ${NAME} ${OBJS}

clean:
	@rm -f ${OBJS}
	@cd ${LIBFTDIR} && make clean

fclean: clean;
	@rm -f ${NAME}
	@cd ${LIBFTDIR} && make fclean

re: fclean all
