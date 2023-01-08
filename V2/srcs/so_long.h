/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:26:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 19:53:27 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft.h"
# include "./gnl/get_next_line.h"
# include "./printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define FALSE   0
# define TRUE    1

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define COLLECTIBLE_IMG    "images/collectible.xpm"
# define WALL_IMG		    "images/wall.xpm"
# define SPACE_IMG		    "images/space.xpm"	
# define PLAYER_IMG         "images/player.xpm"
# define EXIT_IMG           "images/exit.xpm"

# define COLLECTIBLE	'C'
# define SPACE			'0' 
# define WALL			'1'
# define PLAYER			'P'
# define EXIT			'E'

# define KEY_UP     65362
# define KEY_LEFT   65361
# define KEY_RIGHT  65363
# define KEY_DOWN   65364
# define KEY_ESC    65307

# define KEY_W      119
# define KEY_A      97
# define KEY_S      115
# define KEY_D      100
# define KEY_Q      113

typedef struct s_pos{
    size_t  x;
    size_t  y;
}t_pos;

typedef struct s_map{
    char       **map;
    ssize_t     fd;
    size_t     height;
    size_t     width;
    size_t     n_exit;
    size_t     n_player;
    size_t     n_collectibel;
    size_t     steps;
    t_pos      player;
}t_map;

typedef struct s_image{
    void        *xpm_ptr;
	int         x;
	int         y;
}t_image;

typedef struct s_data{
    void        *mlx;
    void        *mlx_win;
    size_t      map_flag;
    t_map       map;
    t_image		collectible;
    t_image		wall;
	t_image		space;
    t_image		player;
	t_image		exit;
}t_data;

void    check_arg(int argc, char **argv, t_data *data);

void    read_map(char *argv, t_data *data);
void    check_empty_line(char *map, t_data *data);

void    init_map(t_map *map);

void    init_all_data(t_data *data);

void    parse_map(t_data *data);
void    check_line(t_data *data);
void    check_column(t_data *data);
void    check_inside(t_data *data);
void    check_parm(t_data *data);
void    check_position(t_data *data);

void    init_other_data(t_data *data);
void    init_mlx(t_data *data);
void    init_image(t_data *data);
t_image xpm_file_to_image(void *mlx, char *path, t_data *data);

int     render_map(t_data *data);
void    id_and_put_image(t_data *data, size_t x, size_t y);

int     key_action(int key, t_data *data);
void    updata_and_render_map(t_data *data, size_t update_x, size_t update_y);

int     win_game(t_data *data);
int     close_game(t_data *data);

void    free_all(t_data *data);
void    destroy_images(t_data *data);
void    free_map(t_data *data);

void    put_error_and_exit(char *str, t_data *data);

#endif