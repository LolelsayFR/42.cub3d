/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:28:05 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 18:59:36 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	handle_input(int keysym, t_c3_data *data)
{
	if (keysym == XK_Escape)
		return (game_close(data), 0);
	else if (keysym == XK_d || keysym == XK_D)
		data->player->control->right = true;
	else if (keysym == XK_a || keysym == XK_A)
		data->player->control->left = true;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->player->control->up = true;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->player->control->down = true;
	else if (keysym == XK_Left)
		data->player->control->turn_left = true;
	else if (keysym == XK_Right)
		data->player->control->turn_right = true;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->player->control->sprint = true;
	else if (keysym == XK_space)
		data->player->control->use = true;
	else if ((keysym == XK_m || keysym == XK_M) && data->mouse)
		mouse_show(data->mlx, data->win, data);
	else if ((keysym == XK_m || keysym == XK_M) && !data->mouse)
		mouse_hide(data->mlx, data->win, data);
	return (0);
}

int	handle_input_keyrelease(int keysym, t_c3_data *data)
{
	if (keysym == XK_d || keysym == XK_D)
		data->player->control->right = false;
	else if (keysym == XK_a || keysym == XK_A)
		data->player->control->left = false;
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		data->player->control->up = false;
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		data->player->control->down = false;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->player->control->sprint = false;
	else if (keysym == XK_Left)
		data->player->control->turn_left = false;
	else if (keysym == XK_Right)
		data->player->control->turn_right = false;
	else if (keysym == XK_space)
		data->player->control->use = false;
	return (0);
}

int	handle_mouse(t_c3_data *data)
{
	int	x;
	int	y;
	int	sizex;
	int	sizey;

	x = 0;
	y = 0;
	sizex = 0;
	sizey = 0;
	if (data->mouse == false)
		return (0);
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	mlx_get_screen_size(data->mlx, &sizex, &sizey);
	data->player->angle -= (x - sizex / 2) * MOUSESPEED;
	mouse_move(data->mlx, data->win, sizex / 2, sizey / 2);
	return (0);
}
