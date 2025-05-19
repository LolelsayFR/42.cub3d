/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 18:17:18 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"


void	game_clock(t_c3_data *data)
{
	(void)data;
	// if (data->is_running == false)
	// 	game_close(data, 0);
}

void	game_start(t_c3_data *data)
{
	//data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_hook(data->win, 17, 0, (void *)game_close, data);
	// mlx_hook(data->win, 2, KeyPressMask, handle_input, &data);
	// mlx_key_hook(data->win, handle_input_keyrelease, &data);
	// mlx_loop_hook(data->mlx, (void *)game_clock, &data);
	mlx_loop(data->mlx);
}
