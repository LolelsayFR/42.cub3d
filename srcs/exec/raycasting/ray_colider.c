/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/06 01:46:36 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	set_anim(t_c3_data *data, t_pos target_pos)
{
	t_door	*door;

	data->ray.color = darker_rgb(C_ODOORS, data->ray.exec_dist);
	data->ray.texture = data->textures->door;
	data->ray.shift_up = 0;
	if (data->map[(int)target_pos.y][(int)target_pos.x] == 'd')
	{
		door = get_door_data(data, target_pos);
		if (door != NULL)
			data->ray.shift_up = door->anim;
	}
}

static bool	ray_assign_door(t_c3_data *data)
{
	if (ray_strchr("D", data, data->ray))
	{
		data->ray.texture = data->textures->door;
		data->ray.color = darker_rgb(C_DOORS, data->ray.dist);
		return (true);
	}
	else
	{
		data->ray.texture = NULL;
		data->ray.color = MAGENTA_PIXEL;
	}
	return (false);
}

static void	ray_assign(t_c3_data *data)
{
	if (ray_assign_door(data))
		return ;
	else if ((int)data->ray.old_pos.y > (int)data->ray.pos.y)
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
		printf(GRN"POS[%c] x = %f y = %f\n\n OLD[%c] x = %f y = %f"RES, data->map[(int)data->ray.pos.y][(int)data->ray.pos.x], data->ray.pos.x, data->ray.pos.y, data->map[(int)data->ray.old_pos.y][(int)data->ray.old_pos.x], data->ray.old_pos.x, data->ray.old_pos.y);
}

void	open_door_colider(t_c3_data *data, int x, double angle)
{
	data->ray.dist = RAY_CORRECTION + data->ray.exec_dist
		* cos(data->ray.angle - angle);
	if (data->map[(int)data->ray.old_pos.y][(int)data->ray.old_pos.x] == 'd')
	{
		set_anim(data, data->ray.old_pos);
		if (data->ray.texture != NULL)
			put_buffer(data, &data->ray, x);
	}
	if (data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'd' &&
		((int)data->ray.pos.x != (int)data->ray.old_pos.x
		|| (int)data->ray.pos.y != (int)data->ray.old_pos.y))
	{
		set_anim(data, data->ray.pos);
		if (data->ray.texture != NULL)
			put_buffer(data, &data->ray, x);
	}
}

void	ray_colider(t_c3_data *data, t_pos pos, int x, double angle)
{
	while (render_distance(data)
		&& (int)data->ray.pos.y < data->map_size[0]
		&& (int)data->ray.pos.x < data->map_size[1]
		&& (int)data->ray.pos.y >= 0 && (int)data->ray.pos.x >= 0
		&& (!ray_strchr("\n D1\0", data, data->ray)))
	{
		data->ray.old_pos = data->ray.pos;
		data->ray.exec_dist += RAY_PRECISION;
		raytrigo(&data->ray, data->ray.exec_dist, pos, data);
		if (((int)data->ray.save_pos.x == (int)data->ray.pos.x
				&& (int)data->ray.save_pos.y == (int)data->ray.pos.y))
			continue ;
		if (ray_strchr("d", data, data->ray) && render_distance(data))
			open_door_colider(data, x, angle);
		data->ray.save_pos = data->ray.pos;
	}
	if (render_distance(data))
		ray_assign(data);
}
