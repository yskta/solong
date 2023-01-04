/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_key_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:33:53 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/04 00:50:59 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_action(int key, t_data *data)
{
    if (key == KEY_UP || key == KEY_W)
        updata_and_render_map(data, data->map.player.x, data->map.player.y - 1, BACK);
    else if (key == KEY_DOWN || key == KEY_S)
        updata_and_render_map(data, data->map.player.x, data->map.player.y + 1, FRONT);
    else if (key == KEY_RIGHT || key == KEY_D)
        updata_and_render_map(data, data->map.player.x, data->map.player.y - 1, BACK);
    else if (key == KEY_LEFT || key == KEY_A)
        updata_and_render_map(data, data->map.player.x - 1, data->map.player.y, LEFT);
    else if (key == KEY_ESC || key == KEY_Q)
        close_game(data);
    return (0);
}

void updata_and_render_map(t_data *data, size_t update_x, size_t update_y, size_t update_player_direction)
{
    size_t  current_x;
    size_t  current_y;

    data->map.player_direction = update_player_direction;
    current_x = data->map.player.x;
    current_y = data->map.player.y;
    if (data->map.map[update_x][update_y] == EXIT & data->map.n_collectibel == 0)
        finish_game(data);
    else if (data->map.map[update_x][update_y] == SPACE || data->map.map[update_x][update_y] == COLLECTIBLE)
    {
        data->map.map[current_x][current_x] == SPACE;
        if (data->map.map[update_x][update_y] == COLLECTIBLE)
            data->map.n_collectibel -= 1;
        data->map.player.x = update_x;
        data->map.player.y = update_y;
        data->map.map[update_x][update_y] = PLAYER;
        data->map.steps++;
        render_map(data);
    }
}