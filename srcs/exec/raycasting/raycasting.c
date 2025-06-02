/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/02 15:39:03 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	frame_put_one_ray(t_c3_data *data, t_ray *ray, int x)
{
	int	y_start;
	int	y_end;
	int	y;

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
	y = HEIGHT;
	while (y >= 0 && y > y_end)
		img_pp(data->frame, WIDTH - x, y--, c_rgb(data->textures->floor));
	y = 0;
	while (y <= HEIGHT && y < y_start)
		img_pp(data->frame, WIDTH - x, y++, c_rgb(data->textures->ceiling));
	while (y <= HEIGHT && y <= y_end - ray->wally * ray->shift_up)
		if (data->player->control->map % 4 == 3 || ray->texture == NULL)
			img_pp(data->frame, WIDTH - x, y++, ray->color);
	else
		texture_apply(data->frame, WIDTH - x, y++, *ray);
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
			reverse_ray_colider(data, pos, angle, x);
			ft_bzero(&data->ray, sizeof(t_ray));
			data->ray.angle = (angle - ((FOV / 2.0) * (N_PI / 180.0))
					+ ((double)x / WIDTH) * FOV * ((N_PI / 180.0)));
			raytrigo(&data->ray, data->ray.exec_dist, pos);
			data->ray.pos = pos;
			data->ray.old_pos = data->ray.pos;
			ray_colider(data, pos);
			data->ray.dist = data->d_test + RAY_CORRECTION + data->ray.exec_dist
				* cos(data->ray.angle - angle);
		}
		frame_put_one_ray(data, &data->ray, x);
		x++;
	}
}
