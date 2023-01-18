/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:40 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/18 01:47:00 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *data)
{
	destroy_images(data);
	free_map(data);
	//https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_destroy_window
	//ウィンドウ インスタンスを破棄
	mlx_destroy_window(data->mlx, data->mlx_win);
	//https://xjman.dsl.gr.jp/X11R6/X11/CH02.html
	//ディスプレイを閉じるもしくはXサーバと接続を切る
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}

void	destroy_images(t_data *data)
{
	//https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_destroy_image
	//イメージ インスタンスを破棄
	mlx_destroy_image(data->mlx, data->collectible.img_ptr);
	mlx_destroy_image(data->mlx, data->wall.img_ptr);
	mlx_destroy_image(data->mlx, data->space.img_ptr);
	mlx_destroy_image(data->mlx, data->player.img_ptr);
	mlx_destroy_image(data->mlx, data->exit.img_ptr);
}

void	free_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.height)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
}
