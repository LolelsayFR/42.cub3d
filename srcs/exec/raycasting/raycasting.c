/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/22 09:49:38 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	vertical_line(t_pos p_pos, double p_ang)
{
	double	ys;     
	double	yn;
	double	tan_a;
	double	c_ang;

	ys = TILE_SIZE;
	yn = p_pos.y - ((p_pos.y / ys) * ys);
	tan_a = tan(p_ang);
	c_ang = p_ang;
	if (c_ang > 90 && c_ang <= 270)
	{
	}
	else
		write(1, "down\n", 5);
}

void	horizontal_line(t_c3_data *data, t_pos p_pos, double p_ang)
{
	int	map_x;
	int	map_y;

	map_x = (int)p_pos.x;
	map_y = (int)p_pos.y;
	//if (c_ang > 90 && c_ang <= 270) | -> this is north direction
	(void)data;
	(void)p_ang;
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->floor_t, 0, HEIGHT / 2);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->ceiling_t, 0, 0);
	horizontal_line(data, pos, angle);
	return ;
}
