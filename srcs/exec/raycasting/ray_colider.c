/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 06:16:43 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	door_assign_anim(t_c3_data *data)
{
	if (data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'D')
	{
		data->ray.texture = data->textures->door;
		data->ray.color = darker_rgb(C_DOORS, data->ray.dist);
	}
	else
	{
		data->ray.color = darker_rgb(C_ODOORS, data->ray.exec_dist);
		data->ray.texture = data->textures->door;
		if (data->map[(int)data->ray.old_pos.y][(int)data->ray.old_pos.x] == 'd'
			&& get_door_data(data, data->ray.old_pos) != NULL)
			data->ray.shift_up = get_door_data(data, data->ray.old_pos)->anim;
		else if (data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'd'
			&& get_door_data(data, data->ray.pos) != NULL)
			data->ray.shift_up = get_door_data(data, data->ray.pos)->anim;
	}
}

static void	ray_assign(t_c3_data *data)
{
	if ((int)data->ray.old_pos.y > (int)data->ray.pos.y)
	{
		data->ray.texture = data->textures->north;
		data->ray.color = darker_rgb(C_N_WALL, data->ray.exec_dist);
	}
	else if ((int)data->ray.old_pos.x > (int)data->ray.pos.x)
	{
		data->ray.texture = data->textures->west;
		data->ray.color = darker_rgb(C_W_WALL, data->ray.exec_dist);
	}
	else if ((int)data->ray.old_pos.y < (int)data->ray.pos.y)
	{
		data->ray.texture = data->textures->south;
		data->ray.color = darker_rgb(C_S_WALL, data->ray.exec_dist);
	}
	else if ((int)data->ray.old_pos.x < (int)data->ray.pos.x)
	{
		data->ray.texture = data->textures->east;
		data->ray.color = darker_rgb(C_E_WALL, data->ray.exec_dist);
	}
	else
	{
		data->ray.texture = data->textures->north;
		data->ray.color = darker_rgb(C_N_WALL, data->ray.exec_dist);
	}
}

static bool	render_distance(t_c3_data *data)
{
	if (data->ray.exec_dist < RENDER_DIST)
	{
		return (true);
	}
	data->ray.texture = NULL;
	data->ray.color = BLACK_PIXEL;
	return (false);
}

void	ray_colider(t_c3_data *data, t_pos pos, int x, double angle)
{
	while (render_distance(data) && !ft_strchr("\n 1\0",
			data->map[(int)data->ray.pos.y][(int)data->ray.pos.x]))
	{
		data->ray.exec_dist += RAY_PRECISION;
		raytrigo(&data->ray, data->ray.exec_dist, pos);
		if ((int)data->ray.save_pos.x == (int)data->ray.pos.x
			&& (int)data->ray.save_pos.y == (int)data->ray.pos.y)
			continue ;
		if (((data->map
					[(int)data->ray.old_pos.y][(int)data->ray.old_pos.x] == 'd'
				|| data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'd')
		&& ((int)data->ray.old_pos.x != (int)data->ray.pos.x
		|| (int)data->ray.old_pos.y != (int)data->ray.pos.y))
		|| data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'D')
		{
			data->ray.dist = RAY_CORRECTION + data->ray.exec_dist
				* cos(data->ray.angle - angle);
			door_assign_anim(data);
			put_buffer(data, &data->ray, x);
		}
		data->ray.save_pos = data->ray.pos;
	}
	if (render_distance(data))
		ray_assign(data);
}
