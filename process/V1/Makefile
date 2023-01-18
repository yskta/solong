# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:08:42 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/08 19:22:57 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT = ./libft/libft.a
PRINTF = ./printf/printf.a
MINILIBX = ./minilibx-linux/libmlx_Linux.a

SRCS = 	./srcs/0_main.c				\
		./srcs/1_check_arg.c			\
		./srcs/2_read_map.c			\
		./srcs/3_init_map.c			\
		./srcs/4_parse_map_1.c			\
		./srcs/4_parse_map_2.c			\
		./srcs/5_init_other_data.c		\
		./srcs/6_render_map.c			\
		./srcs/7_key_action.c			\
		./srcs/8_end_game.c			\
		./srcs/9_free.c				\
		./srcs/10_put_error_and_exit.c	\
		./gnl/get_next_line.c 		\
		./gnl/get_next_line_utils.c	\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) 
	$(CC) $(SRCS) $(CFLAGS) -I . -g3 -Lmlx_Linux -L ./minilibx-linux -Imlx_Linux -L ./libft  -L ./printf -lXext -lX11 -lm -o $(NAME)

$(LIBFT):
	cd ./libft && make all

$(PRINTF):
	cd ./printf && make all

$(MINILIBX):
	cd ./minilibx-linux && make

clean:
	rm -f $(OBJS) $(NAME)
	make clean -C ./libft

fclean:
	clean
	rm -f $(NAME)

re: fclean all