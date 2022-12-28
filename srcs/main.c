/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:00:00 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/28 19:37:31 by yokitaga         ###   ########.fr       */
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

int main(int argc, char *argv[])
{
    static int fd;
    
    fd = open_map(fd, argc, argv);
    
    return(0);
}