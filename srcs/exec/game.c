/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 18:29:53 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	render(t_c3_data *data)
{
	t_pos	pos;

	pos = pos_to_map_pos(data->player->pos.x, data->player->pos.y);
	//REMOVE IN END OF USE !!!!
	printf(YEL"x = %f\ny = %f\n"GRN"Angle = %f\n"RED"char = %c\n"RES,
		pos.x, pos.y, data->player->angle, data->map[(int)pos.y][(int)pos.x]);
	raycasting(data, pos, data->player->angle);
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
	create_minimap_img(data);
	player_init(data);
	data->textures->ceiling_t = img_new(WIDTH, HEIGHT / 2, data);
	data->textures->floor_t = img_new(WIDTH, HEIGHT / 2, data);
	img_put_bg(data->textures->ceiling_t, create_rgb(data->textures->ceiling));
	img_put_bg(data->textures->floor_t, create_rgb(data->textures->floor));
	mlx_hook(data->win, 17, 0, (void *)game_close, data);
	mlx_hook(data->win, 2, KeyPressMask, handle_input, data);
	mlx_key_hook(data->win, handle_input_keyrelease, data);
	mlx_loop_hook(data->mlx, (void *)game_clock, data);
	mlx_do_key_autorepeatoff(data->mlx);
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
