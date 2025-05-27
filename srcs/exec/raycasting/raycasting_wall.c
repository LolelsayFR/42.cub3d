/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/27 13:53:23 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	wall_ray_assign(t_ray *ray, t_c3_data *data)
{
	if ((int)ray->old_pos.y > (int)ray->pos.y)
	{
		ray->texture = data->textures->north;
		ray->color = darker_rgb(C_N_WALL, ray->dist);
	}
	else if ((int)ray->old_pos.x > (int)ray->pos.x)
	{
		ray->texture = data->textures->west;
		ray->color = darker_rgb(C_W_WALL, ray->dist);
	}
	else if ((int)ray->old_pos.y < (int)ray->pos.y)
	{
		ray->texture = data->textures->south;
		ray->color = darker_rgb(C_S_WALL, ray->dist);
	}
	else if ((int)ray->old_pos.x < (int)ray->pos.x)
	{
		ray->texture = data->textures->east;
		ray->color = darker_rgb(C_E_WALL, ray->dist);
	}
}

static t_ray	ray_colider(t_c3_data *data, t_trigo m, t_ray ray, t_pos pos)
{
	while ((int)ray.pos.y >= 0 && (int)ray.pos.y < data->map_size[0]
		&& (int)ray.pos.x >= 0 && (int)ray.pos.x < data->map_size[1]
		&& ft_strchr("\n 1\0",
			data->map[(int)ray.pos.y][(int)ray.pos.x]) == NULL)
	{
		if ((ft_strchr("dD", data->map[(int)ray.old_pos.y][(int)ray.pos.x])
			|| ft_strchr("dD", data->map[(int)ray.pos.y][(int)ray.old_pos.x]))
				&& (int)ray.last_char.x != (int)ray.pos.x
				&& (int)ray.last_char.y != (int)ray.pos.y)
		{
			ray.door_count++;
			ray.last_char = ray.pos;
		}
		ray.old_pos = ray.pos;
		ray.exec_dist += RAY_PRECISION + (ray.dist / 100);
		m = raytrigo(&ray, ray.exec_dist, pos);
		if (ft_strchr("\n 1\0", data->map[(int)ray.old_pos.y][(int)ray.pos.x])
			|| ft_strchr("\n 1\0",
				data->map[(int)ray.pos.y][(int)ray.old_pos.x]))
			break ;
	}
	wall_ray_assign(&ray, data);
	return (ray);
}

void	wall_raycasting(t_c3_data *data, t_pos pos, double angle)
{
	t_ray	ray;
	t_trigo	math;
	int		i;

	i = 0;
	angle = angle * (N_PI / 180.0);
	while (i < WIDTH)
	{
		if (i % RAY_DIVIDER == 0)
		{
			ft_bzero(&ray, sizeof(t_ray));
			ray.angle = angle - (FOV / 2.0) * (N_PI / 180.0)
				+ ((double)i / WIDTH) * FOV * (N_PI / 180.0);
			math = raytrigo(&ray, ray.exec_dist, pos);
			ray.pos = pos;
			ray.old_pos = ray.pos;
			ray = ray_colider(data, math, ray, pos);
			ray.dist = ray.exec_dist * cos(ray.angle - angle);
			data->ray[i] = ray;
		}
		else if (i > 0)
			data->ray[i] = data->ray[i - 1];
		frame_put_one_ray(data, &ray, i);
		i++;
	}
}
