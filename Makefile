# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:17:21 by ivloisy           #+#    #+#              #
#    Updated: 2021/09/16 19:13:13 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

FLAG = -g -Wall -Werror -Wextra

SRCDIR = sources

SRC = $(wildcard $(SRCDIR)/*.c)

HDR = $(wildcard $(SRCDIR)/*.h)

OBJDIR = objects

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LFT = libft/libft.a

all: libft minilibx $(NAME)

libft:
	make -C libft/

minilibx:
	make -C minilibx/

$(NAME): $(OBJ)
	clang -Wall -Werror -Wextra -o $@ $^ $(LFT) -Lminilibx/ -lX11 -lXext -lm -lbsd -lmlx

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDR) | $(OBJDIR)
	$(CC) $(FLAG) -Iminilibx -o $@ -c $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	make -Clibft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all

.PHONY: all clean fclean re libft minilibx

# -g3 -fsanitize=leak