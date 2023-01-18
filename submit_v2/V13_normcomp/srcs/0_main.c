/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:46:33 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/18 02:42:54 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	//mapをfreeするかどうかのflag。data->map.mapを作ったらerrorの時はfreeしないといけないのでflag立てる。
	data->map_flag = FALSE;
	//引数のチェック
	check_arg(argc, argv, data);
	//mapを読み込んでdata->map.mapに入れる
	read_map(argv[1], data);
	//初期化
	init_map(&data->map);
	//内容をチェック
	parse_map(data);
	//その他を初期化
	init_other_data(data);
	//内容を出力
	render_map(data);
	//以降はアクションあればその都度出力
	//フック
	//https://harm-smits.github.io/42docs/libs/minilibx/hooks.html
	//フックは、デバッグや機能の拡張など、多くの目的で使用されます。
	//たとえば、アプリケーションに到達する前にキーボードやマウスのイベント メッセージを傍受したり、動作を監視したり、アプリケーションや別のコンポーネントの機能を変更したりするためにオペレーティング システムの呼び出しを傍受したりすることが含まれます。
	
	//https://xjman.dsl.gr.jp/X11R6/X11/CH10.html
	//X サーバーは入力フォーカスが変わった時にクライアントがその情報を要求しているならば FocusInイベントや FocusOutイベントを通知する。
	//キーボードは、フォーカスウインドウと呼ばれるあるウインドウ （ふつう、ルートウインドウや最上位のウインドウ）に常についている。
	//クライアントは、入力フォーカスがスクリーン上の領域の強調表示を 変える時を知っている必要があるかも知れない。
	//Exposeでもいける
	mlx_hook(data->mlx_win, FocusIn, FocusChangeMask, render_map, data);
	//https://harm-smits.github.io/42docs/libs/minilibx/events.html#x11-masks
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_action, data);
	//X サーバーはウインドウが破棄(destoroy)されると言う情報を要求するクライアントに DestroyNotifyイベントを通知する。
	//X サーバーは、クライアントアプリケーションが XDestroyWindowや XDestroySubwindowsのいずれかを呼ぶ事でウインドウを破棄(destoroy)する時
	//は必ず このイベントを発生する。
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, close_game, data);
	mlx_loop(data->mlx);
	return (0);
}
