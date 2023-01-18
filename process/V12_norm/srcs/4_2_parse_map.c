/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 16:36:56 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void change_recursive(t_map *copy_map, int y, int x)
{    
    //普通処理
    if (copy_map->map[y][x] == COLLECTIBLE)
        copy_map->n_collectibel--;
    
    if (copy_map->map[y][x] == WALL || copy_map->map[y][x] == 'G')
        return;
    else if (copy_map->n_collectibel == 0 && copy_map->map[y][x] == EXIT)
    {
        copy_map->map[y][x] = 'G';
        return ;
    }
    else
        copy_map->map[y][x] = 'G';
    
    //上のマスで再帰
    if ((1 <= y-1) && (1 <= x) && (x <= (int)copy_map->width-2) && (copy_map->map[y-1][x] != 'G'))
        change_recursive(copy_map, y-1, x);
    //左のマスで再帰
    if ((1 <= y) && (y <= (int)copy_map->height-2) && (1 <= x-1) && (copy_map->map[y][x-1] != 'G'))
        change_recursive(copy_map, y, x-1);
    //右のマスで再帰
    if ((1 <= y) && (y <= (int)copy_map->height-2) && (x+1 <= (int)copy_map->width-2) && (copy_map->map[y][x+1] != 'G'))
        change_recursive(copy_map, y, x+1);
    //下のマスで再帰
    if ((y+1 <= (int)copy_map->height-2) && (1 <= x) && (x <= (int)copy_map->width-2) && (copy_map->map[y+1][x] != 'G'))
        change_recursive(copy_map, y+1, x);
    
    //コーナー処理
    if ((y == 1 && x == 1) || (y == 1 && (x == (int)copy_map->width - 2)) || ((y == (int)copy_map->height - 2) && x == 1) || ((y == (int)copy_map->height - 2) && (x == (int)copy_map->width - 2)))
    {
        if (copy_map->map[y][x] == COLLECTIBLE)
            copy_map->n_collectibel--;
        if (copy_map->map[y][x] != WALL && copy_map->map[y][x] != 'G')
            copy_map->map[y][x] = 'G';
        return ;
    }
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

bool check_valid_copy_map(t_map *copy_map)
{
    bool i;
    size_t y;

    i = TRUE;
    y = 0;
    while (y < copy_map->height)
    {
        if (ft_strchr(copy_map->map[y], 'C') != NULL || ft_strchr(copy_map->map[y], 'E') != NULL)
        {
            i = FALSE;
            break;
        }
        y++;
    }
    return (i);
}

void check_playable(t_data *data)
{
    t_map *copy_map;
    
    copy_map = malloc(sizeof(t_map));
    copy_map_data(data, copy_map);
    copy_map->map = copy_map_contents(data, copy_map);
    change_recursive(copy_map, copy_map->player.y, copy_map->player.x);
    if (check_valid_copy_map(copy_map) == FALSE)
    {
        free_copied_map(copy_map);
        free(copy_map);
        put_error_and_exit("INVARID MAP10", data);
    }
    free_copied_map(copy_map);
    free(copy_map);
}