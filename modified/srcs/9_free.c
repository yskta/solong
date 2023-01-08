/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:12:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/06 17:03:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_all(t_data *data)
{
    destroy_images(data);
    free_map(data);
    mlx_destroy_window(data->mlx, data->mlx_win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    free(data);
}

void destroy_images(t_data *data)
{
    mlx_destroy_image(data->mlx, data->collectible.xpm_ptr);
    mlx_destroy_image(data->mlx, data->wall.xpm_ptr);
    mlx_destroy_image(data->mlx, data->space.xpm_ptr);
    mlx_destroy_image(data->mlx, data->player.xpm_ptr);
    mlx_destroy_image(data->mlx, data->exit.xpm_ptr);
}

void free_map(t_data *data)
{
    size_t i;

    i = 0;
    while (i < data->map.height)
    {
        free(data->map.map[i]);
        i++;
    }
    free(data->map.map);
}