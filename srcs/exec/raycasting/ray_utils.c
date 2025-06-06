/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:16:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/06 08:36:08 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

bool	render_distance(t_c3_data *data)
{
	if (data->ray.exec_dist < RENDER_DIST)
	{
		data->ray.texture = NULL;
		data->ray.color = BLACK_PIXEL;
		return (true);
	}
	return (false);
}

bool	ray_strchr(char *set, t_c3_data *data, t_ray ray)
{
	if ((ft_strchr(set, data->map[(int)ray.pos.y][(int)ray.old_pos.x])
		|| ft_strchr(set, data->map[(int)ray.old_pos.y][(int)ray.pos.x])
	|| ft_strchr(set, data->map[(int)ray.pos.y][(int)ray.pos.x])))
		return (true);
	return (false);
}

bool	ray_bicheck(t_c3_data *data, char *set)
{
	t_pos	temp;

	temp.x = data->ray.pos.x;
	temp.y = data->ray.old_pos.y;
	if (ft_strchr(set, data->map[(int)temp.y][(int)temp.x]))
		return (true);
	temp.x = data->ray.old_pos.x;
	temp.y = data->ray.pos.y;
	if (ft_strchr(set, data->map[(int)temp.y][(int)temp.x]))
		return (true);
	return (false);
}

static bool	inmap(t_c3_data *data, t_pos pos)
{
	if ((int)pos.x < 0 || pos.y < 0
		|| (int)pos.x >= data->map_size[1] || pos.y >= data->map_size[0])
		return (false);
	if ((int)pos.x > (int)ft_strlen(data->map[(int)pos.y]))
		return (false);
	return (true);
}

void	*raytrigo(t_ray *ray, double dist, t_pos pos, t_c3_data *data)
{
	t_trigo	math;
	t_pos	temp;

	while (ray->angle < 0)
		ray->angle += 2 * N_PI;
	while (ray->angle >= 2 * N_PI)
		ray->angle -= 2 * N_PI;
	math.angle_rad = ray->angle;
	math.hypo = hypot(dist, 0);
	ray->pos.x = pos.x + math.hypo * sin(ray->angle);
	ray->pos.y = pos.y + math.hypo * cos(ray->angle);
	temp.x = ray->pos.x;
	temp.y = ray->old_pos.y;
	if (inmap(data, temp)
		&& ft_strchr("\n D1\0", data->map[(int)temp.y][(int)temp.x]))
		return (ray->pos = temp, NULL);
	temp.x = ray->old_pos.x;
	temp.y = ray->pos.y;
	if (inmap(data, temp)
		&& ft_strchr("\n D1\0", data->map[(int)temp.y][(int)temp.x]))
		return (ray->pos = temp, NULL);
	return (NULL);
}
