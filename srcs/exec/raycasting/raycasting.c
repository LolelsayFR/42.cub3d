/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/29 15:50:40 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"


static void	frame_put_one_ray(t_c3_data *data, t_ray *ray, int x)
{
	int	y_start;
	int	y_end;
	int	y;

	y = 0;
	if (ray->dist <= 0)
		return ;
	ray->wally = (int)(TILE_SIZE / ray->dist * DIST_FACTOR);
	y_start = HEIGHT / 2 - ray->wally / 2 + MOUSESPEED_Y * data->v_view;
	ray->y_pix = y_start;
	y_end = HEIGHT / 2 + ray->wally / 2 + MOUSESPEED_Y * data->v_view;
	if (y_start < 0)
		y_start = 0;
	if (y_end - ray->wally * ray->shift_up >= HEIGHT)
		y_end = HEIGHT - 1 + ray->wally * ray->shift_up;
	while (y++ <= y_start)
		img_pp(data->frame, WIDTH - x, y, c_rgb(data->textures->ceiling));
	while (y <= y_end - ray->wally * ray->shift_up)
		if (data->player->control->map % 4 == 3 || ray->texture == NULL)
			img_pp(data->frame, WIDTH - x, y++, ray->color);
	else
		texture_apply(data->frame, WIDTH - x, y++, *ray);
	y += ray->wally * ray->shift_up;
	while (y++ <= HEIGHT)
		img_pp(data->frame, WIDTH - x, y, c_rgb(data->textures->floor));
}

void	frame_put_layers_ray(int x, t_c3_data *data)
{
	int	l;

	frame_put_one_ray(data, data->ray[x], x);
	l = data->ray[x][0].door_count;
	while (l > 0)
	{
		frame_put_one_ray(data, &data->ray[x][l], x);
		l--;
	}
}

static void	copy_all_layer(int x, t_c3_data *data)
{
	int	l;

	data->ray[x][0] = data->ray[x - 1][0];
	l = data->ray[x - 1][0].door_count;
	while (l > 0)
	{
		data->ray[x][l] = data->ray[x - 1][l];
		l--;
	}
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	int		x;

	x = 0;
	angle = angle * (N_PI / 180.0);
	while (x < WIDTH)
	{
		if (x % RAY_DIVIDER == 0)
		{
			ft_bzero(data->ray[x], sizeof(t_ray) * RENDER_DIST);
			data->ray[x][0].angle = angle - (FOV / 2.0) * (N_PI / 180.0)
				+ ((double)x / WIDTH) * FOV * (N_PI / 180.0);
			raytrigo(data->ray[x], data->ray[x][0].exec_dist, pos);
			data->ray[x][0].pos = pos;
			data->ray[x][0].old_pos = data->ray[x][0].pos;
			ray_colider(data, x, pos);
			data->ray[x][0].dist = data->ray[x][0].exec_dist
				* cos(data->ray[x][0].angle - angle);
		}
		else if (x > 0)
			copy_all_layer(x, data);
		frame_put_layers_ray(x, data);
		x++;
	}
}
