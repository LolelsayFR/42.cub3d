/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 14:51:53 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	player_posmove(t_c3_data *data, double adj, double opo)
{
	if (data->player->control->up)
	{
		data->player->pos.y += adj;
		data->player->pos.x += opo;
	}
	else if (data->player->control->down)
	{
		data->player->pos.y -= adj;
		data->player->pos.x -= opo;
	}
	if (data->player->control->left)
	{
		data->player->pos.x += adj;
		data->player->pos.y += opo;
	}
	else if (data->player->control->right)
	{
		data->player->pos.x -= adj;
		data->player->pos.y -= opo;
	}
}

static void	player_setpress(t_c3_data *data, double speed)
{
	if ((data->player->control->up || data->player->control->down)
		|| (data->player->control->left || data->player->control->right))
		data->player->to_move = speed;
	else
		data->player->to_move = 0;
	if (data->player->control->turn_left)
		data->player->angle += VIEWSPEED;
	else if (data->player->control->turn_right)
		data->player->angle -= VIEWSPEED;
}

void	player_move(t_c3_data *data)
{
	double	speed;
	t_trigo	math;

	if (data->player->control->sprint)
		speed = RUNSPEED;
	else
		speed = WALKSPEED;
	player_setpress(data, speed);
	math = trigo(data, data->player->to_move, 0);
	player_posmove(data, math.adj, math.opo);
}
