/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:13:58 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 17:14:55 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
            id_image(data, y,x);
            x++;
        }
        y++;
    }
    return(0);
}

