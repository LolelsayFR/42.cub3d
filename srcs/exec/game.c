/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/05 18:04:40 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	game_close(t_c3_data *data)
{
	int	status;

	if (data->exit_status == 2)
		ft_printfd(2, LANG_E, LANG_E_MALLOC);
	data->is_running = false;
	status = data->exit_status;
	ft_alist_free();
	mlx_do_key_autorepeaton(data->mlx);
	free_data(data);
	exit(status);
}

static void	render(t_c3_data *data)
{
	t_pos	pos;

	pos = pos_to_map_pos(data->player->pos.x, data->player->pos.y);
	door_clock(data, pos);
	raycasting(data, pos, data->player->angle);
	mlx_put_image_to_window(data->mlx, data->win, data->frame, 0, 0);
	draw_map(data, 10, 10);
}

static void	game_clock(t_c3_data *data)
{
	if (data->is_running == false)
		game_close(data);
	usleep(1000000 / FPS);
	render(data);
	handle_mouse(data);
	player_move(data);
}

static void	game_init(t_c3_data *data)
{
	data->is_running = true;
	map_size(data);
	data->textures->map_base = img_new(data->map_size[1] * TILE_SIZE,
			data->map_size[0] * TILE_SIZE, data);
	create_minimap_img(data);
	player_init(data);
	data->frame = img_new(WIDTH, HEIGHT, data);
	mlx_hook(data->win, 17, 0, (void *)game_close, data);
	mlx_hook(data->win, 2, KeyPressMask, handle_input, data);
	mlx_key_hook(data->win, handle_input_keyrelease, data);
	mlx_mouse_hook(data->win, handle_mouse_click, data);
	mlx_loop_hook(data->mlx, (void *)game_clock, data);
	//mlx_do_key_autorepeatoff(data->mlx);
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
