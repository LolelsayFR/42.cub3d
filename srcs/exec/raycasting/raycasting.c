/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/25 16:32:04 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	img_put_ray(t_c3_data *data, t_ray *ray)
{
	int	x;
	int	y;
	int	ystart;
	int	yend;
	int	wall_height;

	x = 0;
	while (x < WIDTH)
	{
		if (ray[x].dist > 0)
		{
			wall_height = (int)(TILE_SIZE / ray[x].dist * DIST_FACTOR);
			ystart = HEIGHT / 2 - wall_height / 2 + MOUSESPEED_Y * data->v_view;
			yend = HEIGHT / 2 + wall_height / 2 + MOUSESPEED_Y * data->v_view;
			if (ystart < 0)
				ystart = 0;
			if (yend >= HEIGHT)
				yend = HEIGHT - 1;
			y = ystart;
			while (y <= yend)
				img_pix_put(data->frame, WIDTH - x, y++, ray[x].color);
		}
		x++;
	}
}

static void	update_frame(t_c3_data *data)
{
	const unsigned long	ceiling = create_rgb(data->textures->ceiling);
	const unsigned long	floor = create_rgb(data->textures->floor);

	img_put_dual_bg(data->frame, ceiling, floor, data);
	img_put_ray(data, data->ray);
}

static void	ray_assign(t_ray *ray, t_c3_data *data)
{
	if ((int)ray->old_pos.y > (int)ray->pos.y)
	{
		ray->texture = data->textures->north;
		ray->color = C_N_WALL;
	}
	else if ((int)ray->old_pos.y < (int)ray->pos.y)
	{
		ray->texture = data->textures->south;
		ray->color = C_S_WALL;
	}
	else if ((int)ray->old_pos.x > (int)ray->pos.x)
	{
		ray->texture = data->textures->east;
		ray->color = C_E_WALL;
	}
	else if ((int)ray->old_pos.x < (int)ray->pos.x)
	{
		ray->texture = data->textures->west;
		ray->color = C_W_WALL;
	}
}

static t_ray	ray_colider(t_c3_data *data, t_trigo m, t_ray ray, t_pos pos)
{
	while ((int)ray.pos.y >= 0 && (int)ray.pos.y < data->map_size[0]
		&& (int)ray.pos.x >= 0 && (int)ray.pos.x < data->map_size[1]
		&& data->map[(int)ray.pos.y][(int)ray.pos.x] != '\0'
		&& data->map[(int)ray.pos.y][(int)ray.pos.x] != '\n'
		&& data->map[(int)ray.pos.y][(int)ray.pos.x] != '1'
		&& data->map[(int)ray.pos.y][(int)ray.pos.x] != 'D')
	{
		ray.old_pos = ray.pos;
		ray.dist += RAY_PRECISION;
		m = raytrigo(&ray, ray.dist, pos);
		ray.pos.x = pos.x + m.opo;
		ray.pos.y = pos.y + m.adj;
	}
	ray_assign(&ray, data);
	return (ray);
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
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
			math = raytrigo(&ray, ray.dist, pos);
			ray.pos = pos;
			ray.old_pos = ray.pos;
			ray = ray_colider(data, math, ray, pos);
			ray.dist = ray.dist * cos(ray.angle - angle);
			data->ray[i] = ray;
		}
		else if (i > 0)
			data->ray[i] = data->ray[i - 1];
		i++;
	}
	update_frame(data);
}
