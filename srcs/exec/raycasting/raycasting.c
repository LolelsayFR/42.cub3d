/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 03:02:21 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	put_buffer_pix(t_c3_data *data, int y_end, int y)
{
	while (y <= HEIGHT && y <= y_end - data->ray.wally * data->ray.shift_up)
	{
		if (data->player->control->map % 4 == 3 || data->ray.texture == NULL)
		{
			if (data->ray.buffer[y] == 0)
				data->ray.buffer[y] = data->ray.color;
		}
		else if (data->ray.buffer[y] == 0)
			data->ray.buffer[y] = texture_get_pix(y, data->ray);
		y++;
	}
}

static void	frame_put_column(t_c3_data *data, int x)
{
	int	y;

	y = 0;
	while (y < HEIGHT && y < HEIGHT / 2 + MOUSESPEED_Y * data->v_view)
	{
		if (data->ray.buffer[y] == 0)
			data->ray.buffer[y] = c_rgb(data->textures->ceiling);
		y++;
	}
	y = HEIGHT - 1;
	while (y > 0 && y > HEIGHT / 2 + MOUSESPEED_Y * data->v_view)
	{
		if (data->ray.buffer[y] == 0)
			data->ray.buffer[y] = c_rgb(data->textures->floor);
		y--;
	}
	y = 0;
	while (y < HEIGHT)
	{
		img_pp(data->frame, WIDTH - x, y, data->ray.buffer[y]);
		y++;
	}
}

void	put_buffer(t_c3_data *data, t_ray *ray, int x)
{
	int	y_start;
	int	y_end;
	int	y;

	(void)x;
	ray->wally = (int)(TILE_SIZE / ray->dist * DIST_FACTOR);
	if (ray->dist <= 0 || ray->exec_dist <= 0 || ray->wally <= 0)
		return ;
	y_start = HEIGHT / 2 - ray->wally / 2 + MOUSESPEED_Y * data->v_view;
	ray->y_pix = y_start;
	y_end = HEIGHT / 2 + ray->wally / 2 + MOUSESPEED_Y * data->v_view;
	if (y_start < 0)
		y_start = 0;
	if (y_end - ray->wally * ray->shift_up >= HEIGHT)
		y_end = HEIGHT - 1 + ray->wally * ray->shift_up;
	y = y_start;
	put_buffer_pix(data, y_end, y);
	data->ray.shift_up = 0;
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	int		x;

	x = 0;
	angle *= N_PI / 180.0;
	while (x < WIDTH)
	{
		if (x % RAY_DIVIDER == 0)
		{
			ft_bzero(&data->ray, sizeof(t_ray));
			data->ray.angle = (angle - ((FOV / 2.0) * (N_PI / 180.0))
					+ ((double)x / WIDTH) * FOV * ((N_PI / 180.0)));
			raytrigo(&data->ray, data->ray.exec_dist, pos);
			data->ray.pos = pos;
			data->ray.old_pos = data->ray.pos;
			ray_colider(data, pos, x, angle);
			data->ray.dist = RAY_CORRECTION + data->ray.exec_dist
				* cos(data->ray.angle - angle);
		}
		put_buffer(data, &data->ray, x);
		frame_put_column(data, x);
		x++;
	}
}
