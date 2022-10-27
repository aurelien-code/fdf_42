# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 22:04:09 by aumarin           #+#    #+#              #
#    Updated: 2022/10/27 22:52:05 by aumarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = fdf.c 
OBJ = $(SRC:.c=.o)
C_FLAGS = -Wall -Werror -Wextra

LIBFT_PATH = ./includes/libft
MINILIBX_PATH = ./includes/minilibx/
GNL_PATH = ./includes/get_next_line/

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;33mcompiling... \033[0;37m"
	@make -C $(LIBFT_PATH)
	@gcc $(C_FLAGS)  -I . -c $< -o $(<:.c=.o)
