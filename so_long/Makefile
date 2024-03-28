# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 16:59:36 by tturpin           #+#    #+#              #
#    Updated: 2024/03/28 10:37:51 by tturpin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAG = -Wall -Werror -Wextra

LIBFT = ./Libft/libft.a
LIBFTDIR = ./Libft

MLX_FILE	=	libmlx.a
MLX_FLAG	=	-lX11 -lXext
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

C_FILE		= main.c error_free.c map_check.c map_init.c utils.c init_game.c \
map_rendering.c input.c
SRC_DIR		=	./src/
INC_DIR		=	./includes/
SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

mlx:
	make -sC $(MLX_PATH)


$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(OBJ) $(LIBFT) $(MLX_EX) $(FLAG) -o $(NAME)

$(LIBFT):
	make bonus -C $(LIBFTDIR)

$(MLX_LIB):
	make -C $(MLX_PATH)

clean:
	make clean -sC $(MLX_PATH)
	make clean -C $(LIBFTDIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
