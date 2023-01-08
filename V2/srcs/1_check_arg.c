/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 01:59:42 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/08 16:13:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_arg(int argc, char **argv, t_data *data)
{
    //size_t  len;
    //char    *str;
    
    if (argc != 2)
        put_error_and_exit("ARG ERROR", data);
    (void)argv;
    //len = ft_strlen(argv[1]);
    /*
    if (ft_strnstr(&argv[1][len - 4], ".ber", 4) == NULL)
        put_error_and_exit("ARG ERROR", data);
    str = ft_strtrim(&argv[1][len - 4], ".ber");
    if (ft_strchr(str, '.') != NULL)
        put_error_and_exit("ARG ERROR", data);
    */
    //free(str);
}

