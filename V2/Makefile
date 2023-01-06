# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:08:42 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/06 17:46:10 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/0_main.c \
	   srcs/1_check_arg.c \
	   srcs/2_read_map.c \
	   srcs/3_init_map.c \
	   srcs/4_parse_map_1.c \
	   srcs/4_parse_map_2.c \
	   srcs/5_init_other_data.c \
	   srcs/6_render_map.c \
	   srcs/7_key_action.c \
	   srcs/8_end_game.c \
	   srcs/9_free.c \
	   srcs/10_put_error_and_exit.c \
       gnl/get_next_line.c \
	   gnl/get_next_line_utils.c

MLX = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

LIB = -L ./libft/libft.a -L ./printf/printf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PRINTF):
		cd ./printf && make all

${LIBFT}:
		cd ./libft && make all

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(OBJS) $(LIB) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all