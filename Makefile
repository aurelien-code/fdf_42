# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 22:04:09 by aumarin           #+#    #+#              #
#    Updated: 2022/11/03 21:22:24 by aumarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS =	fdf.c \
		srcs/parser.c
OBJ = $(SRCS:.c=.o)
C_FLAGS = -Wall -Werror -Wextra 
CC = gcc

LIBFT_PATH = ./includes/libft
MINILIBX_PATH = ./includes/minilibx-linux/
FT_PRINT_F_PATH = ./includes/ft_printf/

all: $(NAME)

.c.o:
	@echo "\033[0;33mcompiling... \033[0;37m"
	@$(CC) -o $@ -c $< $(C_FLAGS) -I .

$(NAME): $(OBJ)
	@echo "\033[0;33mcompiling... \033[0;37m"
	@make -C $(LIBFT_PATH)
	@make -C $(MINILIBX_PATH)
	@$(CC)  $(C_FLAGS) -o $@ $^ ./includes/libft/libft.a

clean:
	@echo "\033[0;33mdeleting objects... \033[0;37m"
	@rm -f $(OBJ) $(BONUS_OBJ)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX_PATH)
	@echo "\033[0;33mdone \033[0;37m"

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@make clean -C $(MINILIBX_PATH)
	@rm -f $(NAME)

re: fclean all
