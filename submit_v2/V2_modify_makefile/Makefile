# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 22:44:52 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/18 11:51:57 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT 			= ./library/libft.a
LIBFT_DIR		= ./library
LIBFT_INCLUDE	= $(addprefix -I, $(LIBFT_DIR)/libft.h)


MINILIBX		= ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR	= ./minilibx-linux
MINILIBX_INCLUDE = $(addprefix -I, $(MINILIBX_DIR))

INCLUDE			= $(addprefix -I, $(SRCS_DIR)/so_long.h)

CC 			= cc

CFLAGS 		= -Wall -Werror -Wextra
MINILIBX_FLAGS		= -Lmlx_linux -lXext -lX11 -lm

REMOVE 			= rm -f

SRCS_DIR		= ./srcs/
OBJS_DIR		= ./objs/

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

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))

all:			${LIBFT} ${MINILIBX} ${NAME}

${NAME}: 	${OBJS}
			$(CC) $(CFLAGS) -o $@ $(OBJS) ${MINILIBX} ${LIBFT} ${MINILIBX_FLAGS}

${LIBFT}:
			make all -C library

${MINILIBX}:
			make all -C minilibx-linux

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
			${CC} ${CFLAGS} -c ${INCLUDE} ${MINILIBX_INCLUDE} ${LIBFT_INCLUDE} $< -o $@

clean:
			make clean -C library
			${REMOVE} 

fclean:		clean
			${REMOVE} ${NAME}

re:			fclean all
