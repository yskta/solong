# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:08:42 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/08 17:57:08 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror

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


%.o: %.c
	$(CC) $(CFLAGS) -I/./include -Imlx_linux -O3 -c $< -o $@

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/./libft/libft.a  -L/./printf/printf.a -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	cd ./libft && make all

$(PRINTF)
	cd ./printf && make all

$(MINILIBX)
	cd ./minilibx && ./configure

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all