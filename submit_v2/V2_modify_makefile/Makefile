# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 22:44:52 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/18 15:56:25 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR		= ./srcs/
SRCS 			= $(addprefix $(SRCS_DIR),\
			0_main.c		\
			1_check_arg.c		\
			2_read_map.c		\
			3_init_map.c	\
			4_1_parse_map.c	\
			4_2_parse_map.c		\
			4_3_parse_map.c	\
			5_init_other_data.c		\
			6_render_map.c		\
			7_key_action.c		\
			8_end_game.c 		\
			9_free.c			\
			10_put_error_and_exit.c)

OBJS = $(SRCS:%.c=%.o)

MLX_DIR = ./minilibx-linux
MLX_LIB = -lmlx_Linux -lXext -lX11
MLX_INCLUDE = $(addprefix -I, $(MLX_DIR))

LIBFT_DIR = ./library
LIBFT_LIB = -lft
LIBFT_INCLUDE = $(addprefix -I, $(LIBFT_DIR))

all: mlx libft $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(MLX_DIR) $(MLX_LIB) -L$(LIBFT_DIR) $(LIBFT_LIB)

%.o:	%.c
		$(CC) $(CFLAGS) -c $(MLX_INCLUDE) $(LIBFT_INCLUDE) $< -o $@

mlx:
	make -C $(MLX_DIR)

libft:
	make -C $(LIBFT_DIR)

clean:
	rm -r $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -r $(OBJS_DIR)
	rm $(NAME)
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all