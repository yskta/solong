/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_4_put_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:27:36 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/02 17:26:56 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static voidput_wall_or_field(t_game_info *game_all_data, int width, int height)
{
    if (game_all_data->map_info.game_map[height][width] == '1')
    {
        mlx_put_image_to_window(game_all_data->mlx, game_all_data->window,
        game_all_data->map_part_images.wall.img,
        WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
    }
    else if (info->map_info.game_map[height][width] == '0')
    {
        mlx_put_image_to_window(game_all_data->mlx, game_all_data->window,
        game_all_data->map_part_images.field.img,
        WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
    }
}

static voidput_other_elements(t_game_info *game_all_data, int width, int height)
{
    if (game_all_data->map_info.game_map[height][width] == 'C')
    {
        mlx_put_image_to_window(game_all_data->mlx, game_all_data->window,
        game_all_data->map_part_images.collect.img,
        WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
    }
    else if (game_all_data->map_info.game_map[height][width] == 'M')
    {
        mlx_put_image_to_window(game_all_data->mlx, game_all_data->window,
        game_all_data->map_part_images.enemy.img,
        WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
    }
    else if (game_all_data->map_info.game_map[height][width] == 'P')
    {
        mlx_put_image_to_window(game_all_data->mlx, game_all_data->window,
        game_all_data->player.img_1.img,
        WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
    }
    else if (game_all_data->map_info.game_map[height][width] == 'E')
    {
        mlx_put_image_to_window(game_all_data->mlx, game_all_data->window,
        game_all_data->map_part_images.exit.img,
        WIDTH_IMAGE * width, HEIGHT_IMAGE * height);
    }
}

static void put_image(t_game_info *game_all_data, int width, int height)
{
    if (ft_strchr("10", game_all_data->map_info.game_map[height][width]))
    {
        put_wall_or_field(info, width, height);
    }
    else if (ft_strchr("CMPE", game_all_data->map_info.game_map[height][width]))
    {
        put_other_elements(info, width, height);
}
}

void put_map(t_game_info *game_all_data)
{
    int height;
    int width;
    
    height = 0;
    width = 0;
    while (height < game_all_data->map_info.height)
    {
        while (width < game_all_data->map_info.width)
        {
            put_image(game_all_data, width, height);
            width += 1;
        }
        width = 0;
        height += 1;
    }
}