# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 15:25:29 by elebouch          #+#    #+#              #
#    Updated: 2018/03/08 18:38:46 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

SRC_DIR = ./src/
OBJ_DIR = ./obj/
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE) -g
CPPFLAGS = -I./inc -I./libft/inc
LDFLAGS = -Llibft/
LDLIBS = -lft
MAKE = make
RM = rm -f

HEADER = \
		inc/minishell.h \

SRC= \
	execute.c \
	free.c \
	launch.c \
	main.c \
	parser.c \
	bltin_cd.c \
	bltin_echo.c \
	bltin_env.c \
	bltin_setenv.c \
	bltin_unsetenv.c \
	bltin_exit.c \
	env.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: lib $(NAME)

$(NAME):  $(OBJ)
	@echo "\n\033[94mCompiling minishell\033[0m"
	@$(CC) $(CFLAGS) $(CPPFLAGS)  $(OBJ)  -o $(NAME) $(LDFLAGS) $(LDLIBS)
	@echo  "\033[34mDone\033[0m"

lib:
	@$(MAKE) -C libft/

obj/%.o: src/%.c $(HEADER)
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS)  -o $@ -c $<

clean:
	@$(MAKE) clean -C libft/
	@$(RM) $(OBJ)
	@rmdir  $(OBJ_DIR) 2> /dev/null || true

fclean: clean
	@$(MAKE) fclean -C libft/
	@$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: clean fclean re all lib
