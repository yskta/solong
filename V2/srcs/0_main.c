/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:26:50 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/04 10:23:28 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char *argv[])
{
    t_data  *data;

    data->flag = FALSE;
    check_arg(argc, argv, data);
    read_map(argv[1], data);
    parse_map(data);
    init_all_data(data);
    render_map(data);
    mlx_hook(data->mlx_win, DESTROY_NOTIFY, 1L << 17, close_game, data);
    mlx_key_hook(data->mlx_win, key_action, data);
    mlx_loop_hook(data->mlx, render_map, data);
    mlx_loop(data->mlx);
    free_all(data);
}