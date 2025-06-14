/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:28:05 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:16 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	handle_input(int key, t_c3_data *data)
{
	if (key == XK_Escape)
		return (game_close(data), 0);
	else if (key == XK_d || key == XK_D)
		data->player->control->right = true;
	else if (key == XK_a || key == XK_A)
		data->player->control->left = true;
	else if (key == XK_w || key == XK_W || key == XK_Up)
		data->player->control->up = true;
	else if (key == XK_s || key == XK_S || key == XK_Down)
		data->player->control->down = true;
	else if (key == XK_Left)
		data->player->control->turn_left = true;
	else if (key == XK_Right)
		data->player->control->turn_right = true;
	else if (key == XK_Shift_L || key == XK_Shift_R)
		data->player->control->sprint = true;
	else if (key == XK_m || key == XK_M)
		data->player->control->map++;
	else if (key == XK_space && data->mouse)
		mouse_show(data->mlx, data->win, data);
	else if (key == XK_space && !data->mouse)
		mouse_hide(data->mlx, data->win, data);
	else if (key == XK_e || key == XK_E || key == XK_F || key == XK_f)
		door_using(data);
	return (0);
}

int	handle_input_keyrelease(int key, t_c3_data *data)
{
	if (key == XK_d || key == XK_D)
		data->player->control->right = false;
	else if (key == XK_a || key == XK_A)
		data->player->control->left = false;
	else if (key == XK_w || key == XK_W || key == XK_Up)
		data->player->control->up = false;
	else if (key == XK_s || key == XK_S || key == XK_Down)
		data->player->control->down = false;
	else if (key == XK_Shift_L || key == XK_Shift_R)
		data->player->control->sprint = false;
	else if (key == XK_Left)
		data->player->control->turn_left = false;
	else if (key == XK_Right)
		data->player->control->turn_right = false;
	return (0);
}

int	handle_mouse(t_c3_data *data)
{
	int	x;
	int	y;
	int	sizex;
	int	sizey;
	int	my;

	x = 0;
	y = 0;
	sizex = 0;
	sizey = 0;
	if (data->mouse == false)
		return (0);
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	mlx_get_screen_size(data->mlx, &sizex, &sizey);
	my = (y - sizey / 2) * MOUSESPEED_X;
	data->player->angle -= (x - sizex / 2) * MOUSESPEED_X;
	if (data->v_view - my > -(WIDTH / 2) && data->v_view - my < (WIDTH / 2))
		data->v_view -= my;
	mouse_move(data->mlx, data->win, sizex / 2, sizey / 2);
	return (0);
}

int	handle_mouse_click(int button, int x, int y, t_c3_data *data)
{
	if (button == 9)
		data->d_test += 0.01;
	if (button == 8)
		data->d_test -= 0.01;
	if (button == 2)
		data->d_test = 0;
	if (button == 2)
		data->v_view = 0;
	if (button == 1 || button == 3)
		door_using(data);
	return ((void)x, (void)y, 0);
}
