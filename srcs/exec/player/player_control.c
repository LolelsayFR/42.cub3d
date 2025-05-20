/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 21:49:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	player_angle_move(t_c3_data *data)
{
	double	opo;
	double	adj;
	double	hypo;

	if (data->player->angle > 360)
		data->player->angle -= 360;
	if (data->player->angle < 1)
		data->player->angle += 360;
	hypo = sqrt(data->player->to_move[0]) + sqrt(data->player->to_move[1]);
	opo = hypo * sin(data->player->angle);
	adj = hypo * cos(data->player->angle);
	data->player->pos[0] += opo;
	data->player->pos[1] += adj;
}

void	player_move(t_c3_data *data)
{
	int	speed;

	if (data->player->control->sprint)
		speed = RUNSPEED;
	else
		speed = WALKSPEED;
	if (data->player->control->up)
		data->player->to_move[0] = speed;
	else if (data->player->control->down)
		data->player->to_move[0] = speed;
	else
		data->player->to_move[0] = 0;
	if (data->player->control->left)
		data->player->to_move[1] = speed;
	else if (data->player->control->right)
		data->player->to_move[1] = speed;
	else
		data->player->to_move[1] = 0;
	if (data->player->control->turn_left)
		data->player->angle -= VIEWSPEED;
	else if (data->player->control->turn_right)
		data->player->angle += VIEWSPEED;
	else
		data->player->to_move[1] = 0;
	player_angle_move(data);
}

