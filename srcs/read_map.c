/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:35:48 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 15:38:17 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//read_map(fd, &game_all_data->map_data);
void read_map(int fd, t_map_data  *map_data)
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
    if (map_data->game_map == NULL)
        exit_and_put_error(READ_ERROR);
}