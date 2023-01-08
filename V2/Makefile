# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:08:42 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/08 18:40:11 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CFLAGS = -Wall -Wextra -Werror

CC = cc

LIBFT = ./libft/libft.a
PRINTF = ./printf/printf.a
MINILIBX = ./minilibx-Linux/libmlx_Linux.a

SRCS = 	./src/0_main.c				\
		./src/1_check_arg.c			\
		./src/2_read_map.c			\
		./src/3_init_map.c			\
		./src/4_parse_map_1.c			\
		./src/4_parse_map_2.c			\
		./src/5_init_other_data.c		\
		./src/6_render_map.c			\
		./src/7_key_action.c			\
		./src/8_end_game.c			\
		./src/9_free.c				\
		./src/10_put_error_and_exit.c	\
		./gnl/get_next_line.c 		\
		./gnl/get_next_line_utils.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX)
	$(CC) $(SRCS) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	cd ./libft && make all

$(PRINTF):
	cd ./printf && make all

$(MINILIBX):
	cd ./minilibx-Linux && make

clean:
	rm -f $(LIBFT_OBJS) $(NAME)
	make clean -C ./libft

fclean:
	clean
	rm -f $(NAME)

re: fclean all