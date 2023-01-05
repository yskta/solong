/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_end_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:58:58 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/05 15:52:49 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int win_game(t_data *data)
{
    ft_printf("steps: %d\n", data->map.steps);
    free_all(data);
    ft_printf("WIN\n");
    exit(1);
}

int close_game(t_data *data)
{
    ft_printf("steps: %d\n", data->map.steps);
    free_all(data);
    ft_printf("CLOSED\n");
    exit(1);
}