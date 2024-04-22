# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 08:10:18 by tturpin           #+#    #+#              #
#    Updated: 2024/04/22 09:21:05 by tturpin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= pipex

LIBFT = ./Libft/libft.a
LIBFTDIR = ./Libft

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c error_free.c child.c init.c path.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
HEAD	= -I ./header/

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

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
