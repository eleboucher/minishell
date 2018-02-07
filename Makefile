# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:25:29 by elebouch          #+#    #+#              #
#    Updated: 2018/02/07 16:13:43 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRC_DIR = ./src/
OBJ_DIR = ./obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE)
CPPFLAGS = -I./includes -I./libft/includes
LDFLAGS = -Llibft/
LDLIBS = -lftprintf
MAKE = make


HEADER = \
		includes/minishell.h
SRC= \
	 main.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: lib $(NAME)

$(NAME):  $(OBJ)
	@echo "\033[94mCompiling ft_ls\033[0m"
	@$(CC) $(CFLAGS) $(CPPFLAGS)  $(OBJ)  -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@echo  "\033[34mDone\033[0m"

lib:
	@echo "\033[94mCompiling libft and printf\033[0m"
	@$(MAKE) -C libft/

obj/%.o: src/%.c $(HEADER) 
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CPPFLAGS)  -o $@ -c $<

clean:
	@$(MAKE) clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

.PHONY: clean  fclean re all lib

