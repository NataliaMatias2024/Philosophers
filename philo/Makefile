# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 11:29:54 by namatias          #+#    #+#              #
#    Updated: 2026/03/22 15:15:45 by namatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                       FLAGS AND VARIABLES TO COMPILE                         #
################################################################################

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Wall -g3

SRC_DIR = 		./src/
OBJ_DIR = 		./obj/
INCLUDE_DIR = 	./include/

SRC_FILES = main.c \
			time.c \
			parse.c \
			init.c \
			clean.c   

FILES_O = $(SRC_FILES:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(FILES_O))
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

################################################################################
#                   	          LIBRARIES        		                       #
################################################################################

INCLUDES = -I $(INCLUDE_DIR)

################################################################################
#                                   COLORS                                     #
################################################################################

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

################################################################################
#                          		   FUNCTIONS	                               #
################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "[\033[0;32mOK\033[0m] $(NAME) COMPILED!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "[\033[0;32mOK\033[0m] COMPILED $<"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[\033[0;32mOK\033[0m] FILES CLEAR!"

fclean: clean
	@rm -f $(NAME)
	@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"

re: fclean all

val: all
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re val
