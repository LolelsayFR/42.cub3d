/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_doors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/27 18:14:55 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	door_ray_assign(t_ray *ray, t_c3_data *data)
{
	if (data->map[(int)ray->pos.y][(int)ray->pos.x] == 'D')
	{
		ray->texture = data->textures->door;
		ray->color = darker_rgb(C_DOORS, ray->dist);
	}
	else if (data->map[(int)ray->pos.y][(int)ray->pos.x] == 'd')
	{
		ray->texture = data->textures->door;
		ray->color = darker_rgb(C_ODOORS, ray->dist);
		ray->shift_up = 0.8;
	}
}

static t_ray	ray_colider(t_c3_data *data, t_trigo m, t_ray ray, t_pos pos)
{
	int		count;

	count = 0;
	ray.save_pos = ray.pos;
	while ((int)ray.pos.y >= 0 && (int)ray.pos.y < data->map_size[0]
		&& (int)ray.pos.x >= 0 && (int)ray.pos.x < data->map_size[1]
		&& ft_strchr("\n 1\0",
			data->map[(int)ray.pos.y][(int)ray.pos.x]) == NULL)
	{
		m = raytrigo(&ray, ray.exec_dist, pos);
		if (ft_strchr("Dd", data->map[(int)ray.pos.y][(int)ray.pos.x])
			&& (int)ray.save_pos.x != (int)ray.pos.x
			&& (int)ray.save_pos.y != (int)ray.pos.y)
		{
			count++;
			ray.save_pos = ray.pos;
			if (count == ray.door_count)
				break ;
		}
		ray.old_pos = ray.pos;
		ray.exec_dist += RAY_PRECISION + (ray.dist / 100);
	}
	door_ray_assign(&ray, data);
	return (ray);
}

void	door_raycasting(t_c3_data *data, t_pos pos, double angle)
{
	t_ray	ray;
	t_trigo	math;
	int		i;

	i = 0;
	angle = angle * (N_PI / 180.0);
	while (i < WIDTH)
	{
		ray = data->ray[i];
		while (ray.door_count > 0)
		{
			ft_bzero(&ray, sizeof(t_ray));
			ray.save_pos = data->ray[i].save_pos;
			ray.door_count = data->ray[i].door_count;
			ray.angle = angle - (FOV / 2.0) * (N_PI / 180.0)
				+ ((double)i / WIDTH) * FOV * (N_PI / 180.0);
			math = raytrigo(&ray, ray.exec_dist, pos);
			ray.pos = pos;
			ray.old_pos = ray.pos;
			ray = ray_colider(data, math, ray, pos);
			ray.dist = ray.exec_dist * cos(ray.angle - angle);
			data->ray[i] = ray;
			data->ray[i].door_count--;
			frame_put_one_ray(data, &ray, i);
		}
		i++;
	}
}
