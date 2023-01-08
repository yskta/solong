/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_put_error_and_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:19:55 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/06 17:03:53 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_error_and_exit(char *str, t_data *data)
{
    if (data->map_flag == TRUE)
        free_map(data);
    free(data);
    ft_printf("%s\n", str);
    exit(1);
}