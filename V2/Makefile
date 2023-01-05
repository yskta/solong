# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 17:20:47 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/05 18:25:09 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

GEN_FLAGS = -Wall -Werror -Wextra
MLX_FLSGS = = -lmlx -lXext -lX11

LIBFT = ./libft/libft.a
SRCS_DIR = ./srcs

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
			make all

