/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/11 16:34:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_position(t_data *data)
{
    size_t x;
    size_t y;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            if (data->map.map[y][x] == COLLECTIBLE || data->map.map[y][x] == EXIT || data->map.map[y][x] == PLAYER)
            {
                if (data->map.map[y-1][x-1] == WALL && data->map.map[y-1][x] == WALL && data->map.map[y-1][x+1] == WALL && data->map.map[y][x-1] == WALL && data->map.map[y][x+1] == WALL && data->map.map[y+1][x-1] == WALL && data->map.map[y+1][x] == WALL && data->map.map[y+1][x+1] == WALL)
                    put_error_and_exit("INVALID MAP10", data);
            }
            x++;
        }
        y++;
    }
}

/*
void check_partition(t_data *data)
{
    check_line_parti(data);
    check_column(data);
}
*/