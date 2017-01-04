# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 01:49:59 by vthomas           #+#    #+#              #
#    Updated: 2017/01/04 02:07:36 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select

SRC_NAME = main.c\
		   init/setup/s_init.c\
		   init/setup/save_term.c\
		   init/setup/set_option.c\
		   init/setup/set_signal.c\
		   other/output.c

OBJ_NAME = $(SRC_NAME:.c=.o)

DBG_OUTPUT = /dev/ttys001
SRC_PATH = ./src/
OBJ_PATH = ./obj/
OBJ_SUB = init\
		  init/input\
		  init/setup\
		  loop\
		  other

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))

LIB = -L libft -L DebugLib -lft -ldbg -lncurses
INC = -I include -I libft -I DebugLib/include
FMW =

CC = clang

#CFLAGS = -Wall -Wextra -Weverything -Wno-missing-noreturn -g -Wno-padded
CFLAGS = -Wall -Wextra -g -Wno-unused-parameter -Ofast -Os

all: $(NAME)

$(NAME): lib $(OBJ)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mSources\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
	@printf "\033[34m▶    \033[4mLINK\033[0;34m    ◀\033[0m\n"
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIB) $(FMW) -o $@
	@chmod +x $(NAME)
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mLink\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"

lib:
	@printf "\033[34m▶    \033[4mLIBRAIRIES\033[0;34m    ◀\033[0m\n"
	@printf "\033[32;4m▶\tLIBFT\033[0m\n"
	@make -C ./libft
	@printf "\033[32;4m▶\tLIBDBG\033[0m\n"
	@make -C ./DebugLib
	@printf "\033[34;1m\n▶    \033[0;32;1m✔ \033[0;34;1mLibrairies\033[0;32;1m ✔\033[0;34;1m    ◀\033[0m\n"
	@printf "\033[90m--------------------------------------------------------------------------------\033[0m\n"
	@printf "\033[34m▶    \033[4mSOURCES\033[0;34m    ◀\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	-@mkdir -p $(addprefix $(OBJ_PATH),$(OBJ_SUB))
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	-@rm -rf $(OBJ_PATH)
	@make -C ./libft $@
	@make -C ./DebugLib $@

fclean: clean
	-@rm $(NAME)
	@make -C ./libft $@
	@make -C ./DebugLib $@
	@printf "🦄  There is no more unicorn poop 🦄\n"

re: fclean all

test: all
	@clear
	@clear > $(DBG_OUTPUT)
	@echo "\033[32;4m`date`\033[0m\n" >> $(DBG_OUTPUT)
	ls -1 | ./$(NAME) 2>> $(DBG_OUTPUT)
#	env -i ./$(NAME) 2>> $(DBG_OUTPUT)

norme:
	@make -C libft norme
	@norminette src/**/*.c
	@norminette include/*.h

.PHONY: fclean clean
