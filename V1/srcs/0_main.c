/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:00:00 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/02 13:34:01 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_game_all_data(t_game_all_data *game_all_data)
{
    init_map_data(&game_all_data->map_data);
    init_map_image(&game_all_data->map_image);
    init_player_data(&game_all_data->player_data);
}

static void starting_game(int fd, t_game_all_data *game_all_data)
{
    read_map(fd, &game_all_data->map_data);
    check_map(&game_all_data->map_data);
    set_map(game_all_data);
    put_map(game_all_data);
    set_key_hook(game_all_data);
}

static void continueing_game(t_game_all_data *game_all_data)
{
    mlx_loop_hook(game_all_data->mlx,  render_next_frame, game_all_data);
    mlx_loop(game_all_data->mlx);
}

static void end_game(t_game_all_data *game_all_data)
{
    
}

int main(int argc, char *argv[])
{
    static int fd = 0;
    t_game_all_data game_all_data;

    init_game_all_data(&game_all_data);
    fd = open_map(fd, argc, argv);
    starting_game(fd, &game_all_data);
    continueing_game();
    end_game();
    return(0);
}