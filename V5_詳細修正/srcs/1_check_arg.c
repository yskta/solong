/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:06 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/13 17:11:16 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_arg(const int argc, const char *argv[], t_data *data)
{
    (void)argv;
    if (argc != 2)
        put_error_and_exit("ARG ERROR1", data);
    check_extenxiton(argv[1]);
}

void check_extention(const char *argv)
{
    const char *extention = ".ber";
    char  *str;
    size_t argv_len;
    size_t ext_len = 4;

    argv_len = ft_strlen(argv);
    if (ft_strchr(argv, '.') == NULL || argv_len <= ext_len)
        put_error_and_exit("ARG ERROR2", data);
    while(ext_len)
    {
        ext_len--;
        argv_len--;
        if (argv[argv_len] != extention[ext_len])
            put_error_and_exit("ARG ERROR3", data);
    }
    str = ft_strtrim(argv, extention);
    if(ft_strchr(argv, '.') != NULL)
        put_error_and_exit("ARG ERROR4", data);
}