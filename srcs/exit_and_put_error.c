/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_put_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:13:28 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 18:57:01 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_and_put_error(int type_of_error)
{
    if (type_of_error == WRONG_ARGC)
        ft_putstr_fd("Error(Wrong argc)\n", 1);
    else if (type_of_error == OPEN_ERROR)
        ft_putstr_fd("Error(Open failed)\n", 1);
    else if (type_of_error == READ_ERROR)
        ft_putstr_fd("Error(Read failed)\n", 1);
    else if (type_of_error == INVARID_MAP)
        ft_putstr_fd("Error(Invalid map)\n", 1);
    else if (type_of_error == ERROR_AT_MLX_INIT)
        ft_putstr_fd("Error at mlx_init\n", 1);
    else if (type_of_error == ERROR_AT_MLX_WIN)
        ft_putstr_fd("Error at mlx_win\n", 1);
    else if (type_of_error == ERROR_AT_XPM_TO_FILE)
        ft_putstr_fd("Error at set_image\n", 1);
    
    exit(1);
}