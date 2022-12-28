/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:00:00 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/28 23:44:25 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../gnl/get_next_line.h"

int open_map(int fd, int argc, char argv[])
{
    if (argc != 2)
        exit_and_put_error(WRONG_ARGC);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_and_put_error(OPEN_ERROR);
    return (fd);
}

void init_map(map_data_t map_data)
{
    map_data->game_map = NULL;
    map_data->height = 0;
    map_data->width = 0;
    map_data->nbr_of_enemy = 0;
    map_data->nbr_of_collectable = 0;
    map_data->nbr_of_exit = 0;
    map_data->nbr_of_player = 0;
}

void read_map(int fd, map_data_t  map_data)
{
    char *read_line;
    int  line;

    line = 0;
    while (read_map != NULL)
    {
        read_line = get_next_line(fd);
        map_data->game_map[line] = read_line;
        free(read_line);
        line++;
    }
    if ()
}

void map_check(char *game_map[])
{
       
}

int main(int argc, char *argv[])
{
    static int  fd;
    map_data_t  map_data;

    fd = open_map(fd, argc, argv);
    init_map(map_data);
    read_map(fd, map_data);
    map_check(map_data->game_map);
    return(0);
}