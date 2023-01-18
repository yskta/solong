/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:14 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 23:24:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_map(t_map *map)
{
    map->width = 0;
    map->n_exit = 0;
    map->n_player = 0;
    map->n_collectibel = 0;
    map->steps = 0;
}
