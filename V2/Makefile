# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:20:47 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/05 18:40:23 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLSGS = = -lmlx -lXext -lX11

MLX_DIR = ./mlx
PRINTF_DIR = ./printf
LIBFT_DIR = ./libft
SRCS_DIR = ./srcs
OBJS_DIR = ./objs 

PRINTF = $(PRINTF_DIR)/printf.a
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(addprefix $(SRCS_DIR), 
		0_main.c 
		1_check_arg.c 
		2_read_map.c 
		3_init_map.c 
		4_parse_map_1.c 
		5_parse_map_2.c 
		6_render_map.c 
		7_key_action.c 
		8_end_game.c 
		9_free.c 
		10_put_error_and_exit.c 
		)

${LIBFT}:
		cd $(LIBFT_DIR) && make all

$(PRINTF):
		cd $(PRINTF_DIR) && make all

$(NAME): 
		$(CC) $(SRCS) $(LIBFT) $(PRINTF) $(CFLAGS) $(MLX_FLSGS) -o $(NAME)

all: $(NAME)

clean:

fclean:

re:	fclean all

.PHONY: all clean fclean re

