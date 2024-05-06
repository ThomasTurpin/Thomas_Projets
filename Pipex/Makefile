# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 08:10:18 by tturpin           #+#    #+#              #
#    Updated: 2024/05/06 16:09:54 by tturpin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3
NAME	= pipex
NAME_BONUS = pipex_bonus

LIBFT = ./Libft/libft.a
LIBFTDIR = ./Libft

SRC_PATH = src/
OBJ_PATH = obj/
SRC_BONUS_PATH = src_bonus/

SRC		= main.c error_free.c child.c init.c path.c utils.c

SRC_BONUS = pipex_bonus.c path_bonus.c init_bonus.c here_doc.c error_free_bonus.c child_bonus.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
SRCS_B = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS_BONUS = $(SRCS_B:.c=.o)
HEAD	= -I ./header/pipex.h

all: $(LIBFT) $(OBJ_PATH) $(NAME)

$(LIBFT):
	make bonus -C $(LIBFTDIR)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ_PATH)
	rm -f ${OBJS_BONUS}

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFTDIR)

re: fclean all

bonus:${OBJS_BONUS}
	make
	${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBFT} -o ${NAME_BONUS}

.PHONY: all clean fclean re
