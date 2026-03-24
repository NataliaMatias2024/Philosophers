# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namatias <namatias@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/20 11:29:54 by namatias          #+#    #+#              #
#    Updated: 2026/03/24 00:57:01 by namatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                       FLAGS AND VARIABLES TO COMPILE                         #
################################################################################

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #TODO: retirar o -g3 antes d enviar

SRC_DIR = 		./src/
OBJ_DIR = 		./obj/
INCLUDE_DIR = 	./include/

SRC_FILES = main.c \
			time.c \
			init.c \
			parse.c \
			clean.c \
			utils.c \
			routine.c \
			threads.c \
			monitoring.c

FILES_O = $(SRC_FILES:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(FILES_O))
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

ARGS = 5 800 200 200 #Para compilar com a regra make val para projetos q devem receber argumentos pelo terminal
                     #Esses valores sao substituidos ao se chamar make val ARGS="1 200 200 200 200" por exemplo
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

# Para ver vazamentos de memória (Leaks)
val: all
	valgrind -q --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARGS)

# Para ver problemas de Threads e Data Races
hel: all
	valgrind -q --tool=helgrind ./$(NAME) $(ARGS)

.PHONY: all clean fclean re val
