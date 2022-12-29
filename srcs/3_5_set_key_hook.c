/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_set_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:37:28 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 19:00:15 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

voidset_key_hook(t_game_all_data *game_all_data)
{
    mlx_hook(game_all_data->mlx_win, DESTROY_NOTIFY, 1L << 17, close_window, game_all_data);
    mlx_hook(game_all_data->mlx_win, FOCUS_IN, 1L << 21, re_draw_map, game_all_data);
    mlx_key_hook(game_all_data->mlx_win, key_action, game_all_data);
}