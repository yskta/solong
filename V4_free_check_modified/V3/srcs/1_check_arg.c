/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:06 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/11 21:28:14 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_arg(int argc, char **argv, t_data *data)
{
    (void)argv;
    if (argc != 2)
        put_error_and_exit("ARG ERROR", data);   
}