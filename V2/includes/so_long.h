/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:26:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/02 18:17:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define SPACE			'0'
# define WALL			'1'

typedef struct s_data{
    t_map map;
    t_win win;
    t_pos player_pos;
}t_data;


typedef struct s_win{
    void *mlx;
    void *mlx_win;
}t_win;

typedef struct s_map{
    char       **map;
    size_t     height;
    size_t     width;
}t_map;

typedef struct s_pos{
    size_t  x;
    size_t  y;
}t_pos;




#endif