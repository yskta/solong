/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:30 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/13 12:06:45 by yokitaga         ###   ########.fr       */
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
            id_and_put_image(data, y, x);
            x++;
        }
        y++;
    }
    return(0);
}

void id_and_put_image(t_data *data, size_t y, size_t x)
{
    if (data->map.map[y][x] == COLLECTIBLE)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->collectible.img_ptr, x * data->collectible.x, y * data->collectible.y);
    else if (data->map.map[y][x] == SPACE)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->space.img_ptr, x * data->space.x , y * data->space.y);
    else if (data->map.map[y][x] == WALL)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->wall.img_ptr, x * data->wall.x , y * data->wall.y);
    else if (data->map.map[y][x] == EXIT)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->exit.img_ptr, x * data->exit.x , y * data->exit.y);
    else if (data->map.map[y][x] == PLAYER)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->player.img_ptr, x * data->player.x, y * data->player.y);
}
