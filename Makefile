# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enshertid <enshertid@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/22 14:32:42 by enshertid         #+#    #+#              #
#    Updated: 2020/04/22 15:41:54 by enshertid        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src

OBJ_DIR = obj

INC_DIR = includes

LIB = lib

FLAGS = -Wall -Wextra -Werror

SRCS = main.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc $(FLAGS) -I$(INC_DIR)/ -I$(INC_DIR)/SDL2  -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
	@gcc $(OBJ) -L $(LIB) -framework SDL2 -o $(NAME)

clean:
	@rm -Rf $(OBJ_DIR)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
