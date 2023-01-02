/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:26:50 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 02:41:31 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char *argv[])
{
    t_data  *data;

    data->flag = FALSE;
    check_arg(argc, argv, data);
    read_map(argv[1], data);
    check_map(data);
    init_all(data);
    render_map(data);
    mlx_hook();
    mlx_hook();
    mlx_hook();
    mlx_loop();
    ft_free();
}