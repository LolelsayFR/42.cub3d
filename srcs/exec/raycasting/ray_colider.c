/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/29 15:37:16 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	door_ray_assign(int x, t_c3_data *data)
{
	int	l;

	data->ray[x]->save_pos = data->ray[x]->pos;
	data->ray[x]->door_count++;
	l = data->ray[x]->door_count;
	data->ray[x][l].dist = data->ray[x][0].exec_dist
		* cos(data->ray[x][0].angle - (data->player->angle * (N_PI / 180.0)));
	data->ray[x][l].pos = data->ray[x][0].pos;
	data->ray[x][l].old_pos = data->ray[x][0].old_pos;
	if (data->map[(int)data->ray[x][l].pos.y]
			[(int)data->ray[x][l].pos.x] == 'D')
	{
		data->ray[x][l].texture = data->textures->door;
		data->ray[x][l].color = darker_rgb(C_DOORS, data->ray[x][l].dist);
		data->ray[x][l].shift_up = 0; // change value to anim
	}
	else if (data->map[(int)data->ray[x][l].pos.y]
			[(int)data->ray[x][l].pos.x] == 'd')
	{
		data->ray[x][l].texture = data->textures->door;
		data->ray[x][l].color = darker_rgb(C_ODOORS, data->ray[x][l].dist);
		data->ray[x][l].shift_up = 0.8;
	}
}

static void	wall_ray_assign(int x, t_c3_data *data)
{
	if ((int)data->ray[x]->old_pos.y > (int)data->ray[x]->pos.y)
	{
		data->ray[x]->texture = data->textures->north;
		data->ray[x]->color = darker_rgb(C_N_WALL, data->ray[x]->exec_dist);
	}
	else if ((int)data->ray[x]->old_pos.x > (int)data->ray[x]->pos.x)
	{
		data->ray[x]->texture = data->textures->west;
		data->ray[x]->color = darker_rgb(C_W_WALL, data->ray[x]->exec_dist);
	}
	else if ((int)data->ray[x]->old_pos.y < (int)data->ray[x]->pos.y)
	{
		data->ray[x]->texture = data->textures->south;
		data->ray[x]->color = darker_rgb(C_S_WALL, data->ray[x]->exec_dist);
	}
	else if ((int)data->ray[x]->old_pos.x < (int)data->ray[x]->pos.x)
	{
		data->ray[x]->texture = data->textures->east;
		data->ray[x]->color = darker_rgb(C_E_WALL, data->ray[x]->exec_dist);
	}
}

static bool	render_distance(t_pos player, t_pos ray, int x, t_c3_data *data)
{
	if ((int)ray.x > (int)player.x - RENDER_DIST
		&& (int)ray.x < (int)player.x + RENDER_DIST
		&& (int)ray.y > (int)player.y - RENDER_DIST
		&& (int)ray.y < (int)player.y + RENDER_DIST)
	{
		data->ray[x]->texture = NULL;
		data->ray[x]->color = BLACK_PIXEL;
		return (true);
	}
	return (false);
}

void	ray_colider(t_c3_data *data, int x, t_pos pos)
{
	while (render_distance(pos, data->ray[x]->pos, x, data)
		&& (int)data->ray[x]->pos.y < data->map_size[0]
		&& (int)data->ray[x]->pos.x < data->map_size[1]
		&& (int)data->ray[x]->pos.y >= 0 && (int)data->ray[x]->pos.x >= 0
		&& !ft_strchr("\n 1\0",
			data->map[(int)data->ray[x]->pos.y][(int)data->ray[x]->pos.x]))
	{
		if (ft_strchr("Dd",
				data->map[(int)data->ray[x]->pos.y][(int)data->ray[x]->pos.x])
			&& !((int)data->ray[x]->save_pos.x == (int)data->ray[x]->pos.x
			&& (int)data->ray[x]->save_pos.y == (int)data->ray[x]->pos.y))
			door_ray_assign(x, data);
		data->ray[x]->old_pos = data->ray[x]->pos;
		data->ray[x]->exec_dist += RAY_PRECISION + (data->ray[x]->dist / 100);
		raytrigo(data->ray[x], data->ray[x]->exec_dist, pos);
		if (ft_strchr("\n 1\0", data->map[(int)data->ray[x]->old_pos.y]
				[(int)data->ray[x]->pos.x])
			|| ft_strchr("\n 1\0", data->map[(int)data->ray[x]->pos.y]
				[(int)data->ray[x]->old_pos.x]))
			break ;
	}
	if (render_distance(pos, data->ray[x]->pos, x, data))
		wall_ray_assign(x, data);
}

