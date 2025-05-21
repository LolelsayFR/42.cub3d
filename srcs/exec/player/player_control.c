/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 13:43:38 by emaillet         ###   ########.fr       */
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
	t_trigo	math;

	if (data->player->control->sprint)
		speed = RUNSPEED;
	else
		speed = WALKSPEED;
	player_setpress(data, speed);
	math = trigo(data, data->player->to_move[0], data->player->to_move[1]);
	player_posmove(data, math.adj, math.opo);
}
