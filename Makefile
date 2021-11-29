# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:17:21 by ivloisy           #+#    #+#              #
#    Updated: 2021/11/29 02:08:51 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

BONUS = so_long_bonus

CC = cc

FLAG = -Wall -Werror -Wextra

LIB = -L minilibx/ -l X11 -l Xext -l m -l bsd -l mlx

SRCDIR = sources

BONDIR = bonus

SRC = ./$(SRCDIR)/background.c \
		./$(SRCDIR)/check_map.c \
		./$(SRCDIR)/exit_error.c \
		./$(SRCDIR)/get_next_line.c \
		./$(SRCDIR)/images.c \
		./$(SRCDIR)/launch.c \
		./$(SRCDIR)/moves.c \
		./$(SRCDIR)/objects.c \
		./$(SRCDIR)/so_long.c \
		./$(SRCDIR)/textures.c

BON = ./$(BONDIR)/background_bonus.c \
		./$(BONDIR)/check_map_bonus.c \
		./$(BONDIR)/exit_error_bonus.c \
		./$(BONDIR)/get_next_line_bonus.c \
		./$(BONDIR)/images_bonus.c \
		./$(BONDIR)/launch_bonus.c \
		./$(BONDIR)/moves_bonus.c \
		./$(BONDIR)/objects_bonus.c \
		./$(BONDIR)/so_long_bonus.c \
		./$(BONDIR)/textures_bonus.c

HDR = ./$(SRCDIR)/get_next_line.h \
		./$(SRCDIR)/so_long.h

BHD = ./$(BONDIR)/get_next_line_bonus.h \
		./$(BONDIR)/so_long_bonus.h

OBJDIR = objects

BOBDIR = objects_bonus

OBJ = $(OBJDIR)/*.o

BOB = $(BOBDIR)/*.o

LFT = ./libft/libft.a

MLX = ./minilibx/obj/*

all: $(NAME)

$(NAME): $(OBJ) $(LFT) $(MLX)
	@echo "\033[36m\n$@ creation\t\t\t\t🛠\n"
	clang $(FLAG) -o $@ $+ $(LIB)
	@echo "\033[35m\n$@ has been created with success !\t\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

bonus:$(BONUS)

$(BONUS): $(BOB) $(LFT) $(MLX)
	@echo "\033[36m\n$@ creation\t\t\t\t🛠\n"
	clang $(FLAG) -o $@ $+ $(LIB)
	@echo "\033[35m\n$@ has been created with success !\t\t🌈\n"

$(BOB): $(BON) $(BHD)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(BON)
	mkdir -p $(BOBDIR)
	mv *.o $(BOBDIR)

$(LFT): ./libft/*.c ./libft/*.h
	make -C libft/

$(MLX):
	make -C minilibx/

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	rm -rf $(OBJDIR) $(BOBDIR)
	make -C libft/ clean
	make -C minilibx/ clean

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	rm -f $(NAME) $(BONUS)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus
