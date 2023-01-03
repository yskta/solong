/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_all_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:06:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 12:16:27 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_all_data(t_data *data)
{
    init_map(data->map);
    init_mlx(data);
    init_image(data);
}

static void init_map(t_map map)
{
    map.width = ft_strlen(map.map[0]);
    map.n_exit = 0;
    map.n_player = 0;
    map.n_collectibel = 0;
    map.steps = 0;
    map.player_image = FRONT;
}

void init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    if (data->mlx == NULL)
        put_error_and_exit("MLX ERROR", data);
    data->mlx_win = mlx_new_window(data->mlx, data->map.width * IMG_WIDTH, data->map.height * IMG_HEIGHT, "S_LONG");
    if (data->mlx_win == NULL)
    {
        free(data->mlx_win);
        put_error_and_exit("MLX_WIN ERROR",data);
    }
}

void init_image(t_data *data)
{
    data->wall = set_image();
}

t_image set_image(char *path, t_data data)
{
    
}