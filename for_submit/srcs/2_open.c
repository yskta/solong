/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_open.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:32:42 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 18:33:05 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_map(int fd, int argc, char argv[])
{
    if (argc != 2)
        exit_and_put_error(WRONG_ARGC);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        exit_and_put_error(OPEN_ERROR);
    return (fd);
}