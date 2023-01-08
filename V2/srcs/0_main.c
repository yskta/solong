/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:26:50 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 19:50:24 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_data  *data;

    data = malloc(sizeof(t_data));
    check_arg(argc, argv, data);
    read_map(argv[1], data);
    init_map(&data->map);
    parse_map(data);
    init_other_data(data);
    render_map(data);
    mlx_hook(data->mlx_win, 9, 1L << 21, close_game, data);
    mlx_key_hook(data->mlx_win, key_action, data);
    mlx_loop_hook(data->mlx, render_map, data);
    mlx_loop(data->mlx);
    return (0);
}