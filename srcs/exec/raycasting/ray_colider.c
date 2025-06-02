/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_colider.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/02 11:09:24 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

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
	if (data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'D')
	{
		data->ray.texture = data->textures->door;
		data->ray.color = darker_rgb(C_DOORS, data->ray.dist);
	}
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

void	ray_colider(t_c3_data *data, t_pos pos)
{
	while (render_distance(data)
		&& (int)data->ray.pos.y < data->map_size[0]
		&& (int)data->ray.pos.x < data->map_size[1]
		&& (int)data->ray.pos.y >= 0 && (int)data->ray.pos.x >= 0
		&& !ft_strchr("\n 1D\0",
			data->map[(int)data->ray.pos.y][(int)data->ray.pos.x]))
	{
		data->ray.old_pos = data->ray.pos;
		data->ray.exec_dist += RAY_PRECISION;
		raytrigo(&data->ray, data->ray.exec_dist, pos);
		if (ft_strchr("\n 1D\0", data->map[(int)data->ray.old_pos.y]
				[(int)data->ray.pos.x])
			|| ft_strchr("\n D1\0", data->map[(int)data->ray.pos.y]
				[(int)data->ray.old_pos.x]))
			break ;
	}
	if (render_distance(data))
		ray_assign(data);
}

void	reverse_ray_colider(t_c3_data *data, t_pos pos, double angle, int x)
{
	int		i;

	while ((int)data->ray.pos.y < data->map_size[0]
		&& (int)data->ray.pos.x < data->map_size[1]
		&& (int)data->ray.pos.y >= 0 && (int)data->ray.pos.x >= 0
		&& data->ray.exec_dist > 0)
	{
		data->ray.old_pos = data->ray.pos;
		data->ray.exec_dist -= RAY_PRECISION;
		raytrigo(&data->ray, data->ray.exec_dist, pos);
		if ((data->map
				[(int)data->ray.old_pos.y][(int)data->ray.old_pos.x] == 'd'
			|| data->map[(int)data->ray.pos.y][(int)data->ray.pos.x] == 'd')
		&& ((int)data->ray.old_pos.x != (int)data->ray.pos.x
		|| (int)data->ray.old_pos.y != (int)data->ray.pos.y))
		{
			data->ray.texture = data->textures->door;
			data->ray.color = darker_rgb(C_ODOORS, data->ray.dist);
			data->ray.dist = data->ray.exec_dist * cos(data->ray.angle - angle);
			data->ray.shift_up = 0.95;
			i = 0;
			while (i <= RAY_DIVIDER)
				frame_put_one_ray(data, &data->ray, x - i++);
		}
	}
}
