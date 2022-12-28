/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:00:11 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/28 23:46:21 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAX_LINES      100000
# define WRONG_ARGC     1
# define OPEN_ERROR     2
# define READ_ERROR     3
# define INVARID_MAP    4 

typedef struct map_datas{
    char    *game_map[MAX_LINES];
    int     height;
    int     width;
    int     nbr_of_enemy;
    int     nbr_of_collectable;
    int     nbr_of_exit;
    int     nbr_of_player;
}map_data_t;

typedef struct game_datas{
    map_data_t  map_data;
}game_data_t;


#endif