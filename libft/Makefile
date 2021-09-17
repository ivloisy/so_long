# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 02:59:11 by ivloisy           #+#    #+#              #
#    Updated: 2021/08/20 14:25:30 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -I -g -Wall -Werror -Wextra

SRC = $(wildcard *.c)

HDR = $(wildcard *.h)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[36m\nLibrary creation\t\t\t\t🧱\n"
	ar rc $@ $(OBJ)
	ranlib $@
	@echo "\033[35m\n$(NAME) has been created with success !\t\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	/bin/rm -f $(OBJ)

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re