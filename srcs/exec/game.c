/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 19:39:51 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	render(t_c3_data *data)
{
	if (data->is_running == false)
		game_close(data);
	//raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->map_base, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->map_player,
		data->player->pos[1] - MINIPLAYER / 2,
		data->player->pos[0] - MINIPLAYER / 2);
}

static void	game_clock(t_c3_data *data)
{
	usleep(1000000 / FPS);
	render(data);
	player_move(data);
	data->player->control->angle %= 360;
	ft_printf("ANGLE WIEW = %i\n", data->player->control->angle);
}

static void	game_init(t_c3_data *data)
{
	data->is_running = true;
	map_size(data);
	create_minimap_img(data);
	player_init(data);
	data->textures->map_player = img_new(MINIPLAYER, MINIPLAYER, data);
	img_put_background(data->textures->map_player, RED_PIXEL);
	mlx_hook(data->win, 17, 0, (void *)game_close, data);
	mlx_hook(data->win, 2, KeyPressMask, handle_input, data);
	mlx_key_hook(data->win, handle_input_keyrelease, data);
	mlx_loop_hook(data->mlx, (void *)game_clock, data);
}

void	game_start(t_c3_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (data->win == NULL)
	{
		data->exit_status = 2;
		game_close(data);
	}
	game_init(data);
	mlx_loop(data->mlx);
}
