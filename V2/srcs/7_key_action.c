/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_key_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:33:53 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 23:31:41 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_action(int keysym, t_data *data)
{
    if (keysym == KEY_UP || KEY_W)
        updata_and_render_map(data, data->map.player.x, data->map.player.y - 1, BACK);
    else if (keysym == KEY_DOWN || KEY_S)
        updata_and_render_map(data, data->map.player.x, data->map.player.y + 1, FRONT);
    else if (keysym == KEY_RIGHT || KEY_D)
        updata_and_render_map(data, data->map.player.x, data->map.player.y - 1, BACK);
    else if (keysym == KEY_LEFT || KEY_A)
        updata_and_render_map(data, data->map.player.x - 1, data->map.player.y, LEFT);
    else if (keysym == KEY_ESC || KEY_Q)
        
    return (0);
}

void updata_and_render_map(t_data *data, size_t update_x, size_t update_y, size_t player_direction)
{
    size_t  current_x;
    size_t  current_y;
    
}