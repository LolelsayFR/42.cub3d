/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 20:32:24 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	player_angle_move(t_c3_data *data)
{
	data->player->pos[0] += data->player->to_move[0];
	data->player->pos[1] += data->player->to_move[1];
}

void	player_move(t_c3_data *data)
{
	int	speed;

	if (data->player->control->sprint)
		speed = RUNSPEED;
	else
		speed = WALKSPEED;
	if (data->player->control->up)
		data->player->to_move[0] = -speed;
	else if (data->player->control->down)
		data->player->to_move[0] = speed;
	else
		data->player->to_move[0] = 0;
	if (data->player->control->left)
		data->player->to_move[1] = -speed;
	else if (data->player->control->right)
		data->player->to_move[1] = speed;
	else
		data->player->to_move[1] = 0;
	player_angle_move(data);
}

