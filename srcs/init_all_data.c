/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 00:23:40 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 15:08:20 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_map_data(t_map_data *map_data)
{
    map_data->map = NULL;
    map_data->height = 0;
    map_data->width = 0;
    map_data->nbr_of_enemy = 0;
    map_data->nbr_of_collectable = 0;
    map_data->nbr_of_exit = 0;
    map_data->nbr_of_player = 0;
}

void init_each_map_image_data(t_image *image)
{
    image->img = NULL;
    image->line = 0;
    image->column = 0;
}

void init_map_image(t_map_image *map_image)
{
    init_each_map_image_data(&map_image->space);
    init_each_map_image_data(&map_image->wall);
    init_each_map_image_data(&map_image->collectable);
    init_each_map_image_data(&map_image->exit);
    init_each_map_image_data(&map_image->enemy);
}

void init_player_data(t_player_data *player_data)
{
    init_each_map_image_data(&player_data->player);
    player_data->total_steps = 0;
    player_data->collected_cnt = 0;
    player_data->current_position_line = 0;
    player_data->current_position_column = 0;
}

