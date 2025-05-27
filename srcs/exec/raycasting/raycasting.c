/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/27 13:57:51 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	frame_put_one_ray(t_c3_data *data, t_ray *ray, int x)
{
	int	y;
	int	y_end;

	if (ray->dist > 0)
	{
		ray->wally = (int)(TILE_SIZE / ray->dist * DIST_FACTOR);
		y = HEIGHT / 2 - ray->wally / 2 + MOUSESPEED_Y * data->v_view;
		ray->y_pix = y;
		y_end = HEIGHT / 2 + ray->wally / 2 + MOUSESPEED_Y * data->v_view;
		if (y < 0)
			y = 0;
		if (y_end - ray->wally * ray->shift_up >= HEIGHT)
			y_end = HEIGHT - 1 + ray->wally * ray->shift_up;
		while (y <= y_end - ray->wally * ray->shift_up)
			if (data->player->control->map % 4 == 3)
				img_pix_put(data->frame, WIDTH - x, y++, ray->color);
		else
			texture_apply(data->frame, WIDTH - x, y++, *ray);
	}
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	const unsigned long	ceiling = create_rgb(data->textures->ceiling);
	const unsigned long	floor = create_rgb(data->textures->floor);

	img_put_dual_bg(data->frame, ceiling, floor, data);
	wall_raycasting(data, pos, angle);
	door_raycasting(data, pos, angle);
}
