/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:59:42 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/04 10:03:23 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void chech_arg(int argc, char *argv, t_data *data)
{
    if (argc != 2)
        put_error_and_exit("ARG ERROR", data);
    //.berの対応必要
}

