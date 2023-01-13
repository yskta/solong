/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/14 00:35:23 by yokitaga         ###   ########.fr       */
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
                if (data->map.map[y-1][x] == WALL && data->map.map[y][x-1] == WALL && data->map.map[y][x+1] == WALL && data->map.map[y+1][x] == WALL)
                    put_error_and_exit("INVALID MAP10", data);
            }
            x++;
        }
        y++;
    }
}

/*
void check_playable(t_data *data)
{
    t_data *check_data;
    
    check_data = malloc(sizeof(t_data));
    check_data->map.height = data->map.height;
    check_data->map.width = data->map.width;
    check_data->map.n_collectibel = data->map.n_collectibel;
    check_data->map.map = copy_map(data);
    
    free(check_data);
}

void copy_map(t_data *data)
{
    char    **copy_map;
    size_t  y;
    size_t  i;

    copy_map = (char **)malloc(sizeof(char *) * data->map.height);
    if (copy_map == NULL)
    {
        free(check_data);
        put_error_and_exit("MALLOC ERROR AT COPY MAP", data);
    }
    y = 0;
    while (y < data->map.height)
    {
        copy_map[y] = ft_strdup(data->map.map[y]);
        if (copy_map[y] == NULL)
        {
            i = 0;
            while(copy_map[i] != NULL)
            {
                free(copy_map[i]);
                i++;
            }
            free(copy_map);
            put_error_and_exit("COPY MAP ERROR", data);
        }
        y++;
    }
    return(copy_map);
}
*/