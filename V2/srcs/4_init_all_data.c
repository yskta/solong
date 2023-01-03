/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_init_all_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:06:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 20:34:40 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_all_data(t_data *data)
{
    init_map(data->map);
    init_mlx(data);
    init_image(data);
}

void init_map(t_map map)
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
    data->collectible = xpm_file_to_image(data->mlx, COLLECTIBLE_IMG, data);
    data->wall = xpm_file_to_image(data->mlx, WALL_IMG, data);
    data->space = xpm_file_to_image(data->mlx, COLLECTIBLE_IMG, data);
    data->player_front = xpm_file_to_image(data->mlx, PLAYER_FRONT_IMG, data);
    data->player_back = xpm_file_to_image(data->mlx, PLAYER_BACK_IMG, data);
    data->player_right = xpm_file_to_image(data->mlx, PLAYER_RIGHT_IMG, data);
    data->player_left = xpm_file_to_image(data->mlx, PLAYER_LEFT_IMG, data);
    data->exit = xpm_file_to_image(data->mlx, EXIT_IMG, data);
}

t_image xpm_file_to_image(void *mlx, char *path, t_data *data)
{
    t_image image;
    
    image.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &image.x, &image.y);
    if (image.xpm_ptr == NULL)
        put_error_and_exit("XPM_TO_IMAGE ERROR", data);
    return(image);
}