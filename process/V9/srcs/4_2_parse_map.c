/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_parse_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:22 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/15 12:34:57 by yokitaga         ###   ########.fr       */
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

void change_above(t_map *copy_map, int y, int x)
{
    if (copy_map->map[y-1][x] == COLLECTIBLE)
    {
        copy_map->map[y-1][x] = 'X';
        copy_map->n_collectibel--;
    }
    if (copy_map->map[y-1][x] == WALL || copy_map->map[y-1][x] == 'X' || copy_map->map[y-1][x] == 'G')
        return;
    else
        copy_map->map[y-1][x] = 'X';
}

void change_down(t_map *copy_map, int y, int x)
{
    if (copy_map->map[y+1][x] == COLLECTIBLE)
    {
        copy_map->map[y+1][x] = 'X';
        copy_map->n_collectibel--;
    }     
    if (copy_map->map[y+1][x] == WALL || copy_map->map[y+1][x] == 'X' || copy_map->map[y+1][x] == 'G')
        return;
    else
        copy_map->map[y+1][x] = 'X';
}

void change_left(t_map *copy_map, int y, int x)
{
    if (copy_map->map[y][x-1] == COLLECTIBLE)
    {
        copy_map->map[y][x-1] = 'X';
        copy_map->n_collectibel--;
    }
    if (copy_map->map[y][x-1] == WALL || copy_map->map[y][x-1] == 'X' || copy_map->map[y][x-1] == 'G')
        return;
    else
        copy_map->map[y][x-1] = 'X';
}

void change_right(t_map *copy_map, int y, int x)
{
    if (copy_map->map[y][x+1] == COLLECTIBLE)
    {
        copy_map->map[y][x+1] = 'X';
        copy_map->n_collectibel--;
    }
    if (copy_map->map[y][x+1] == WALL || copy_map->map[y][x+1] == 'X' || copy_map->map[y][x+1] == 'G')
        return;
    else
        copy_map->map[y][x+1] = 'X';
}

void change_recursive(t_map *copy_map, int y, int x)
{
    copy_map->map[y][x] = 'G';
    //各コーナーの時の処理
    if ((y == 1 && x == 1) || (y == 1 && (x == (int)copy_map->width - 2)) || ((y == (int)copy_map->height - 2) && x == 1) || ((y == (int)copy_map->height - 2) && (x == (int)copy_map->width - 2)))
    {
        if (copy_map->map[y][x] == COLLECTIBLE)
            copy_map->n_collectibel--;
        if (copy_map->map[y][x] != WALL && copy_map->map[y][x] != 'X')
            copy_map->map[y][x] = 'G';
        //コーナーの時は終わらせる
        return ;
    }
    //左上のコーナーの時の再帰
    if ((y-1 == 1) && (x-1 == 1))
        change_recursive(copy_map, 1, 1);
    //右上のコーナーの時の再帰
    else if ((y-1 == 1) && (x+1 == (int)copy_map->width - 2))
        change_recursive(copy_map, 1, copy_map->width - 2);
    //左下のコーナーの時の再帰
    else if ((y+1 == (int)copy_map->height - 2) && (x-1 == 1))
        change_recursive(copy_map, copy_map->height - 2, 1);
    //右下のコーナーの時の再帰
    else if ((y+1 == (int)copy_map->height - 2) && (x+1 == (int)copy_map->width - 2))
        change_recursive(copy_map, copy_map->height - 2, copy_map->width - 2);
    
    change_above(copy_map, y, x);
    if (copy_map->n_collectibel == 0)
        return ;
    change_down(copy_map, y, x);
    if (copy_map->n_collectibel == 0)
        return ;
    change_left(copy_map, y, x);
    if (copy_map->n_collectibel == 0)
        return ;
    change_right(copy_map, y, x);
    if (copy_map->n_collectibel == 0)
        return ;
    //上のマスで再帰
    if ((2 <= y-1) && (2 <= x) && (x <= (int)copy_map->width-3) && (copy_map->map[y-1][x] != 'G'))
        change_recursive(copy_map, y-1, x);
    //左のマスで再帰
    if ((2 <= y) && (y <= (int)copy_map->height-3) && (2 <= x-1) && (copy_map->map[y][x-1] != 'G'))
        change_recursive(copy_map, y, x-1);
    //右のマスで再帰
    if ((2 <= y) && (y <= (int)copy_map->height-3) && (x+1 <= (int)copy_map->width-3) && (copy_map->map[y][x+1] != 'G'))
        change_recursive(copy_map, y, x+1);
    //下のマスで再帰
    if ((y+1 <= (int)copy_map->height-3) && (2 <= x) && (x <= (int)copy_map->width-3) && (copy_map->map[y+1][x] != 'G'))
        change_recursive(copy_map, y+1, x);
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
    change_recursive(copy_map, copy_map->player.y, copy_map->player.x);
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