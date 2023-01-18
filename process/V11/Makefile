# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 22:44:52 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/15 15:45:00 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT 			= ./library/libft.a
MINILIBX		= ./minilibx-linux/libmlx_Linux.a

CC 			= clang

CFLAGS 		= -Wall -Werror -Wextra
MINILIBX_FLAGS		= -Lmlx_linux -lXext -lX11 -lm

REMOVE 			= rm -f

SRCS_DIR		= ./srcs/

SRCS 			= $(addprefix $(SRCS_DIR),\
			0_main.c		\
			1_check_arg.c		\
			2_read_map.c		\
			3_init_map.c	\
			4_1_parse_map.c	\
			4_2_parse_map.c		\
			5_init_other_data.c		\
			6_render_map.c		\
			7_key_action.c		\
			8_end_game.c 		\
			9_free.c			\
			10_put_error_and_exit.c)

all:			${LIBFT} ${MINILIBX} ${NAME}

${NAME}: 	
			${CC} ${CFLAGS} ${SRCS} ${MINILIBX} ${LIBFT} ${MINILIBX_FLAGS} -o ${NAME}

${LIBFT}:
			make all -C library

${MINILIBX}:
			make all -C minilibx-linux

clean:
			make clean -C library
			${REMOVE} 

fclean:		clean
			${REMOVE} ${NAME}

re:			fclean all

run:		${NAME}
			${VALGRIND} ./${NAME} map/map.ber