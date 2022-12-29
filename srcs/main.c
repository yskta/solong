/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:00:00 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 15:50:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../gnl/get_next_line.h"

static void init_game_all_data(t_game_all_data *game_all_data)
{
    init_map_data(&game_all_data->map_data);
    init_map_image(&game_all_data->map_image);
    init_player_data(&game_all_data->player_data);
}

static void prepare_for_starting_game(int fd, t_game_all_data *game_all_data)
{
    read_map(fd, &game_all_data->map_data);
    check_map(&game_all_data->map_data);
    set_map(game_all_data);
}

static int open_map(int fd, int argc, char argv[])
{
    if (argc != 2)
        exit_and_put_error(WRONG_ARGC);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_and_put_error(OPEN_ERROR);
    return (fd);
}

/*
void map_check(char *game_map[])
{
    //追記予定
    exit_and_put_error(INVARID_MAP);
}
*/

int main(int argc, char *argv[])
{
    static int fd;
    t_game_all_data game_all_data;
    
    fd = 0;
    init_game_all_data(&game_all_data);
    fd = open_map(fd, argc, argv);
    prepare_for_starting_game(fd, &game_all_data);
    
    return(0);
}