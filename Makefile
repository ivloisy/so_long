# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:17:21 by ivloisy           #+#    #+#              #
#    Updated: 2021/09/21 22:09:34 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

FLAG = -Wall -Werror -Wextra

SRCDIR = sources

SRC = ./sources/background.c \
		./sources/check_map.c \
		./sources/exit_error.c \
		./sources/get_next_line.c \
		./sources/images.c \
		./sources/launch.c \
		./sources/moves.c \
		./sources/objects.c \
		./sources/so_long.c \
		./sources/textures.c

HDR = ./sources/get_next_line.h \
		./sources/so_long.h

OBJDIR = objects

OBJ = $(OBJDIR)/*.o

LFT = ./libft/libft.a

MLX = ./minilibx/obj/*

all: $(NAME)

$(NAME): $(OBJ) $(LFT) $(MLX)
	@echo "\033[36m\n$(NAME) creation\t\t\t\t🧱\n"
	clang $(FLAG) -o $@ $+ -L minilibx/ -l X11 -l Xext -l m -l bsd -l mlx
	@echo "\033[35m\n$(NAME) has been created with success !\t\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

$(LFT): ./libft/*.c ./libft/*.h
	make -C libft/

$(MLX):
	make -C minilibx/

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	rm -rf $(OBJDIR)
	make -C libft/ clean
	make -C minilibx/ clean

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re

# -g3 -fsanitize=leak