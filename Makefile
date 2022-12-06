# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 22:04:09 by aumarin           #+#    #+#              #
#    Updated: 2022/12/06 03:17:08 by aumarin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS =	fdf.c \
		srcs/parser.c \
		srcs/ll_actions.c \
		srcs/render.c \
		srcs/hooks.c \
		srcs/bresenham.c \
		srcs/scale.c
OBJ = $(SRCS:.c=.o)
C_FLAGS = -g3 -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CC = cc

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
	@$(CC) $(OBJ) $(C_FLAGS) $(MLX_FLAGS) -o $(NAME) ./includes/libft/libft.a \
		./includes/minilibx-linux/libmlx_Linux.a \

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
