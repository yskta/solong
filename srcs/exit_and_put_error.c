/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_put_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:13:28 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/28 19:24:04 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_and_put_error(int type_of_error)
{
    if (type_of_error == WRONG_ARGC)
        ft_putstr_fd("Error(Wrong argc)\n", 1);
    if (type_of_error == OPEN_ERROR)
        ft_putstr_fd("Error(Open failed)\n", 1);
    exit(1);
}