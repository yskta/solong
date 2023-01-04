/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:28:11 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/04 10:51:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void parse_map(t_data *data)
{
    check_line(data);
    check_column(data);
    count_parm(data);
    check_parm(data);
}

void check_line(t_data *data)
{
    size_t y;
    size_t width;

    y = 0;
    width = data->map.map[0];
    while (y < data->map.height)
    {
        if (ft_strlen(ft_strlen(data->map.map[y]) != width)
            put_error_and_exit("INVARID MAP", data);
        if (data->map.map[y][0] != WALL || data->map.map[y][width - 1] != WALL)
            put_error_and_exit("INVARID MAP", data);
        y++;
    }
}

void check_column(t_data *data)
{
    
}

void count_parm(t_data *data)
{
    
}

void check_parm(t_data *data)
{
    
}