/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/14 16:31:07 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_position(t_data *data)
{
    size_t x;
    size_t y;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            if (data->map.map[y][x] == COLLECTIBLE || data->map.map[y][x] == EXIT || data->map.map[y][x] == PLAYER)
            {
                if (data->map.map[y-1][x] == WALL && data->map.map[y][x-1] == WALL && data->map.map[y][x+1] == WALL && data->map.map[y+1][x] == WALL)
                    put_error_and_exit("INVALID MAP10", data);
            }
            x++;
        }
        y++;
    }
}

void copy_map_data(t_data *data, t_map *copy_map)
{
    copy_map->height = data->map.height;
    copy_map->width = data->map.width;
    copy_map->n_collectibel = data->map.n_collectibel;
    copy_map->n_exit = data->map.n_exit;
    copy_map->player.x = data->map.player.x;
    copy_map->player.y = data->map.player.y;
}

char  **copy_map_contents(t_data *data, t_map *copy_map)
{
    char    **copied_map;
    size_t  y;
    size_t  i;

    copied_map = (char **)malloc(sizeof(char *) * data->map.height);
    if (copied_map == NULL)
    {
        free(copy_map);
        put_error_and_exit("MALLOC ERROR AT COPY MAP", data);
    }
    y = 0;
    while (y < data->map.height)
    {
        copied_map[y] = ft_strdup(data->map.map[y]);
        if (copied_map[y] == NULL)
        {
            i = 0;
            while(copied_map[i] != NULL)
            {
                free(copied_map[i]);
                i++;
            }
            free(copy_map);
            put_error_and_exit("COPY MAP ERROR", data);
        }
        y++;
    }
    return(copied_map);
}

void change_map_contents_recursive(t_map *copy_map, size_t y, size_t x)
{
    if (copy_map->map[y][x] == WALL)
        return ;
    else
        copy_map->map[y][x] = 'X';
    if ((copy_map->map[y-1][x] == WALL || copy_map->map[y-1][x] == 'X') && (copy_map->map[y+1][x] == WALL || copy_map->map[y+1][x] == 'X') && (copy_map->map[y][x-1] == WALL || copy_map->map[y][x-1] == 'X') && (copy_map->map[y][x+1] == WALL || copy_map->map[y][x+1] == 'X'))
        return ;
    if (copy_map->map[y-1][x] != WALL)
    {
        copy_map->map[y-1][x] = 'X';
        change_map_contents_recursive(copy_map, y-1, x);
    }
    else if (copy_map->map[y+1][x] != WALL)
    {
        copy_map->map[y+1][x] = 'X';
        change_map_contents_recursive(copy_map, y+1, x);
    }
    else if (copy_map->map[y][x-1] != WALL)
    {
        copy_map->map[y][x-1] = 'X';
        change_map_contents_recursive(copy_map, y, x-1);
    }
    else if (copy_map->map[y][x+1] != WALL)
    {
        copy_map->map[y][x+1] = 'X';
        change_map_contents_recursive(copy_map, y, x+1);
    }
}

void change_map_contents(t_map *copy_map)
{
    copy_map->map[copy_map->player.y][copy_map->player.x] = 'X';
    change_map_contents_recursive(copy_map, copy_map->player.y + 1, copy_map->player.x);
    change_map_contents_recursive(copy_map, copy_map->player.y - 1, copy_map->player.x);
    change_map_contents_recursive(copy_map, copy_map->player.y, copy_map->player.x + 1);
    change_map_contents_recursive(copy_map, copy_map->player.y, copy_map->player.x - 1);
}

void free_copied_map(t_map *copy_map)
{
    size_t i;

    i = 0;
    while (i < copy_map->height)
    {
        free(copy_map->map[i]);
        i++;
    }
    free(copy_map->map);
}

void check_playable(t_data *data)
{
    t_map *copy_map;
    
    copy_map = malloc(sizeof(t_map));
    copy_map_data(data, copy_map);
    copy_map->map = copy_map_contents(data, copy_map);
    change_map_contents(copy_map);
    size_t  i;
    i = 0;
    while (i < copy_map->height)
    {
        ft_printf("%s\n", copy_map->map[i]);
        i++;
    }
    free_copied_map(copy_map);
    free(copy_map);
}