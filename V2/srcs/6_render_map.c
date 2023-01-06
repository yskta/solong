/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:13:58 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/06 17:04:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render_map(t_data *data)
{
    size_t  x;
    size_t  y;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            id_and_put_image(data, x, y);
            x++;
        }
        y++;
    }
    return(0);
}

void id_and_put_image(t_data *data, size_t x, size_t y)
{
    if (data->map.map[y][x] == COLLECTIBLE)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->collectible.xpm_ptr, x, y);
    else if (data->map.map[y][x] == SPACE)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->space.xpm_ptr, x, y);
    else if (data->map.map[y][x] == WALL)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->wall.xpm_ptr, x, y);
    else if (data->map.map[y][x] == EXIT)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->exit.xpm_ptr, x, y);
    else if (data->map.map[y][x] == PLAYER)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->player.xpm_ptr, x, y);
}


