/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_init_other_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:06:47 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/06 18:42:45 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void init_other_data(t_data *data)
{
    init_mlx(data);
    init_image(data);
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
    data->player = xpm_file_to_image(data->mlx, PLAYER_IMG, data);
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