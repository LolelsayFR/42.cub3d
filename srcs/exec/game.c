/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 15:43:12 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	game_clock(t_c3_data *data)
{
	if (data->is_running == false)
		game_close(data);
	mlx_put_image_to_window(data->mlx, data->winmap,
		data->textures->map_base, 0, 0);
	// mlx_put_image_to_window(data->mlx, data->winmap,
	// 	data->textures->map_player, 0, 0);
}

static int	handle_input(int keysym, t_c3_data *data)
{
	if (keysym == XK_Escape)
		return (game_close(data), 0);
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		data->player->control->right = true;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		data->player->control->left = true;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->player->control->up = true;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->player->control->down = true;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->player->control->sprint = true;
	ft_printf(GRN"Key press : %i "RES, keysym);
	return (0);
}

static int	handle_input_keyrelease(int keysym, t_c3_data *data)
{
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		data->player->control->right = false;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		data->player->control->left = false;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->player->control->up = false;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->player->control->down = false;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->player->control->sprint = false;
	ft_printf(RED"Key release : %i "RES, keysym);
	return (0);
}

void	game_start(t_c3_data *data)
{
	map_size(data);
	data->is_running = true;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	create_minimap_img(data);
	if (data->win == NULL)
	{
		data->exit_status = 2;
		game_close(data);
	}
	mlx_hook(data->win, 17, 0, (void *)game_close, data);
	mlx_hook(data->win, 2, KeyPressMask, handle_input, data);
	mlx_key_hook(data->win, handle_input_keyrelease, data);
	mlx_loop_hook(data->mlx, (void *)game_clock, data);
	mlx_loop(data->mlx);
}
