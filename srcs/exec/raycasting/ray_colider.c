/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/05 15:34:13 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	set_anim(t_c3_data *data)
{
	t_pos	temp;

	data->ray.color = darker_rgb(C_ODOORS, data->ray.exec_dist);
	data->ray.texture = data->textures->door;
	if (data->map[(int)data->ray.old_pos.y][(int)data->ray.old_pos.x] == 'd'
		&& get_door_data(data, data->ray.old_pos) != NULL)
		data->ray.shift_up = get_door_data(data, data->ray.old_pos)->anim;
	else if (data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'd'
		&& get_door_data(data, data->ray.pos) != NULL)
		data->ray.shift_up = get_door_data(data, data->ray.pos)->anim;
	temp.x = data->ray.pos.x;
	temp.y = data->ray.old_pos.y;
	if (data->map[(int)temp.y][(int)temp.x] == 'd'
		&& get_door_data(data, temp) != NULL)
		data->ray.shift_up = get_door_data(data, temp)->anim;
	temp.x = data->ray.old_pos.x;
	temp.y = data->ray.pos.y;
	if (data->map[(int)temp.y][(int)temp.x] == 'd'
		&& get_door_data(data, temp) != NULL)
		data->ray.shift_up = get_door_data(data, temp)->anim;
}

static bool	ray_assign_door(t_c3_data *data, bool skip_open_door)
{
	if (!skip_open_door && ray_strchr("d", data, data->ray))
		set_anim(data);
	else if (ray_strchr("D", data, data->ray))
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
	if (ray_assign_door(data, true))
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

static bool	render_distance(t_c3_data *data)
{
	if (data->ray.exec_dist < RENDER_DIST)
	{
		data->ray.texture = NULL;
		data->ray.color = BLACK_PIXEL;
		return (true);
	}
	return (false);
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
		{
			data->ray.dist = RAY_CORRECTION + data->ray.exec_dist
				* cos(data->ray.angle - angle);
			ray_assign_door(data, false);
			if (data->ray.texture != NULL)
				put_buffer(data, &data->ray, x);
		}
		data->ray.save_pos.x = (int)data->ray.pos.x;
		data->ray.save_pos.y = (int)data->ray.pos.y;
	}
	if (render_distance(data))
		ray_assign(data);
}
