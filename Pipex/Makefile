# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturpin <tturpin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 08:10:18 by tturpin           #+#    #+#              #
#    Updated: 2024/05/31 16:32:49 by tturpin          ###   ########.fr        #
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
SRC2 = error_free.c child.c init.c path.c utils.c

SRC_BONUS = pipex_bonus.c here_doc.c child_bonus.c

SRCS2 = $(addprefix $(SRC_PATH), $(SRC2))
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
SRCS_B = $(addprefix $(SRC_BONUS_PATH), $(SRC_BONUS))
OBJ		= $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
OBJS2	= $(addprefix $(OBJ_PATH), $(OBJ2))
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

bonus: $(LIBFT) $(OBJ_PATH) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS2) $(LIBFT) -o $(NAME_BONUS)

clean:
	make clean -C $(LIBFTDIR)
	rm -rf $(OBJ_PATH)
	rm -f ${OBJS_BONUS}

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
