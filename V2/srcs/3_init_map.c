/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_init_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:04:50 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/04 12:06:39 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_map(t_map map)
{
    map.width = 0;
    map.n_exit = 0;
    map.n_player = 0;
    map.n_collectibel = 0;
    map.steps = 0;
    map.player_direction = FRONT;
}