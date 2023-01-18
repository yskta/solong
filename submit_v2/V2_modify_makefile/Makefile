# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 22:44:52 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/18 14:01:36 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

LIBFT 			= ./library/libft.a
LIBFT_DIR		= ./library


MINILIBX		= ./minilibx-linux/libmlx_Linux.a
MINILIBX_DIR	= ./minilibx-linux

CC 			= cc

CFLAGS 		= -Wall -Werror -Wextra
INCLUDE_FLAGS = -I./srcs -I./library -I./minilibx-linux
MINILIBX_FLAGS		= -Lmlx_linux -lXext -lX11 -lm

AR				=	ar rcs
REMOVE 			= rm -f

SRCS_DIR		= ./srcs

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

OBJS		= $(SRCS:%.c=%.o)

all:		$(LIBFT) $(MINILIBX) $(NAME)

$(NAME): 	$(OBJS)
			$(AR) $(NAME) $(OBJS)

$(LIBFT): 
			make all -C library

$(MINILIBX):
			make all -C minilibx-linux

%.o : %.c
			$(CC) $(CFRAGS) -c $(INCLUDE_FLAGS) $< -o $@

clean:
			make clean -C library
			${REMOVE} 

fclean:		clean
			${REMOVE} ${NAME}

re:			fclean all
