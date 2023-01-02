/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:30:53 by yokitaga          #+#    #+#             */
/*   Updated: 2022/12/29 18:23:03 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void set_mlx(t_game_all_data *game_all_data)
{
    game_all_data->mlx = mlx_init();
    if (game_all_data->mlx == NULL)
        exit_and_put_error(ERROR_AT_MLX_INIT);
}

void set_mlx_win(t_game_all_data *game_all_data)
{
    game_all_data->mlx_win = mlx_new_window(info->mlx, WIDTH_IMAGE * info->map_info.width, HEIGHT_IMAGE * info->map_info.height, "so_long");
    if (game_all_data->mlx_win == NULL)
        exit_and_put_error(ERROR_AT_MLX_WIN);
}

void set_xpm_file_to_image(t_game_all_data *game_all_data, t_image *image, char *file_name)
{
    image->img = mlx_xpm_file_to_image(&game_all_data->mlx, file_name, &image->line, &image->column);
    if (image->img == NULL)
        exit_and_put_error(ERROR_AT_XPM_TO_FILE);
}

void set_map(t_game_all_data *game_all_data)
{
    set_mlx(game_all_data);
    set_mlx_win(game_all_data);
    set_xpm_file_to_image(game_all_data, &game_all_data->player_data.player, "");
    set_xpm_file_to_image(game_all_data, &game_all_data->map_image.space, "");
    set_xpm_file_to_image(game_all_data, &game_all_data->map_image.wall, "");
    set_xpm_file_to_image(game_all_data, &game_all_data->map_image.collectable, "");
    set_xpm_file_to_image(game_all_data, &game_all_data->map_image.exit, "");
    set_xpm_file_to_image(game_all_data, &game_all_data->map_image.enemy, "");
    game_all_data->player_data.position_line = game_all_data->map_data.player_position_line;
    game_all_data->player_data.position_column = game_all_data->map_data.player_position_column;
}