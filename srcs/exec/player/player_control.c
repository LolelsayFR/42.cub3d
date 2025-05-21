/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 02:14:40 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	player_posmove(t_c3_data *data, double adj, double opo)
{
	if (data->player->control->up)
	{
		data->player->pos[0] += adj;
		data->player->pos[1] += opo;
	}
	else if (data->player->control->down)
	{
		data->player->pos[0] -= adj;
		data->player->pos[1] -= opo;
	}
	if (data->player->control->left)
	{
		data->player->pos[1] += adj;
		data->player->pos[0] += opo;
	}
	else if (data->player->control->right)
	{
		data->player->pos[1] -= adj;
		data->player->pos[0] -= opo;
	}
}

static void	player_setpress(t_c3_data *data, int speed)
{
	if (data->player->control->up)
		data->player->to_move[0] = speed;
	else if (data->player->control->down)
		data->player->to_move[0] = speed;
	else
		data->player->to_move[0] = 0;
	if (data->player->control->left)
		data->player->to_move[0] = speed;
	else if (data->player->control->right)
		data->player->to_move[0] = speed;
	else
		data->player->to_move[1] = 0;
	if (data->player->control->turn_left)
		data->player->angle += VIEWSPEED;
	else if (data->player->control->turn_right)
		data->player->angle -= VIEWSPEED;
	else
		data->player->to_move[1] = 0;
}


void	player_move(t_c3_data *data)
{
	int		speed;
	double	opo;
	double	adj;
	double	hypo;
	double	angle_rad;

	if (data->player->control->sprint)
		speed = RUNSPEED;
	else
		speed = WALKSPEED;
	player_setpress(data, speed);
	if (data->player->angle >= 360)
		data->player->angle -= 360;
	else if (data->player->angle < 0)
		data->player->angle += 360;
	angle_rad = data->player->angle * (N_PI / 180.0);
	hypo = hypot(data->player->to_move[0], data->player->to_move[1]);
	opo = hypo * sin(angle_rad);
	adj = hypo * cos(angle_rad);
	player_posmove(data, adj, opo);
}

