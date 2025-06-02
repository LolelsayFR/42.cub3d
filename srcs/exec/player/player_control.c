/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:41:42 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/02 18:32:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static bool	player_canmove(t_c3_data *data, double x, double y)
{
	t_pos	go;
	t_pos	player;

	go = pos_to_map_pos(x, y);
	player = pos_to_map_pos(data->player->pos.x, data->player->pos.y);
	if (ft_strchr("1D \n\0", data->map[(int)(go.y + HITBOX)][(int)go.x]) != NULL)
		return (false);
	if (ft_strchr("1D \n\0", data->map[(int)(go.y - HITBOX)][(int)go.x]) != NULL)
		return (false);
	if (ft_strchr("1D \n\0", data->map[(int)go.y][(int)(go.x + HITBOX)]) != NULL)
		return (false);
	if (ft_strchr("1D \n\0", data->map[(int)go.y][(int)(go.x - HITBOX)]) != NULL)
		return (false);
	return (true);
}

static void	player_domove(t_c3_data *data, double x, double y)
{
	if (player_canmove(data, data->player->pos.x, data->player->pos.y + y))
		data->player->pos.y += y;
	if (player_canmove(data, data->player->pos.x + x, data->player->pos.y))
		data->player->pos.x += x;
}

static void	player_posmove(t_c3_data *data, double adj, double opo)
{
	if (data->player->control->up)
		player_domove(data, opo, adj);
	if (data->player->control->down)
		player_domove(data, -opo, -adj);
	if (data->player->control->left)
		player_domove(data, adj, -opo);
	if (data->player->control->right)
		player_domove(data, -adj, opo);
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
	math = trigo(&data->player->angle, data->player->to_move, 0);
	player_posmove(data, math.adj, math.opo);
}
