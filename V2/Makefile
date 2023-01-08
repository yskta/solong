# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 23:08:42 by yokitaga          #+#    #+#              #
#    Updated: 2023/01/08 19:49:04 by yokitaga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

GREEN			= \033[0;32m
RED			= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libft/libft.a
PRINTF			= ./printf/printf.a

CC 			= clang

STANDARD_FLAGS 		= -Wall -Werror -Wextra
MINILIBX_FLAGS		= -lmlx -lXext -lX11

REMOVE 			= rm -f

SRCS_DIR		= ./srcs/

SRCS 			= $(addprefix $(SRCS_DIR),\
			0_main.c		\
			1_check_arg.c		\
			2_read_map.c		\
			3_init_map.c		\
			4_parse_map_1.c		\
			4_parse_map_2.c		\
			5_init_other_data.c		\
			6_render_map.c		\
			7_key_action.c		\
			8_end_game.c		\
			9_free.c		\
			10_put_error_and_exit.c)		\

all:			${LIBFT} ${PRINTF} ${NAME}

${NAME}: 		
			${CC} ${SRCS} ${LIBFT} ${PRINTF} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}

${LIBFT}:
			make all -C libft

${PRINTF}:
			make all -C printf

clean:
			make clean -C libft

fclean:
			${REMOVE} ${NAME}

re:			fclean all

.PHONY:			all clean fclean re rebonus valgrind run run_bonus
