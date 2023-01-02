/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_put_error_and_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:19:55 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 02:27:37 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void put_error_and_exit(char *str, t_data *data)
{
    ft_printf("%s\n", str);
    exit(1);
}