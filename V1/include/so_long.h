/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:00:11 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/02 17:48:52 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WRONG_ARGC -100    
# define OPEN_ERROR -99   
# define READ_ERROR   -98  
# define INVARID_MAP   -97
# define ERROR_AT_MLX_INIT -96
# define ERROR_AT_MLX_WIN -95
# define ERROR_AT_XPM_TO_FILE -94

typedef struct MAP_DATES{
    char       **map;
    size_t     height;
    size_t     width;
    size_t     player_position_line;
    size_t     player_position_column;
    size_t     nbr_of_enemy;
    size_t     nbr_of_collectable;
    size_t     nbr_of_exit;
    size_t     nbr_of_player;
}t_map_data;

typedef struct MAP_IMAGE_DATES{
    void    *img;
    size_t  line;
    size_t  column;
}t_each_map_image_data;


typedef struct MAP_IMAGES{
    t_image space;
    t_image wall;
    t_image collectable;
    t_image exit;
    t_image enemy;
}t_map_image;

typedef struct  PLAYER_DATES{
    t_image player;
    size_t total_steps;
    size_t collected_cnt;
    size_t position_line;
    size_t position_column;
}t_player_data;

typedef struct GAME_ALL_DATAS{
    void *mlx;
    void *mlx_win;
    t_map_data map_data;
    t_map_image map_image;
    t_player_data player_data;
}t_game_all_data;

#endif