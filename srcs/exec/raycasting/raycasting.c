/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/22 08:43:30 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	horizontal_line(t_pos p_pos, double p_ang)
{
	int		cy;
	double	c_ang;

	c_ang = p_ang;
	if (c_ang > 90 && c_ang <= 270)
	{
		cy = (int)p_pos.y;
		printf("%d\n", cy);
	}
	else
		write(1, "down\n", 5);
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->floor_t, 0, HEIGHT / 2);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->ceiling_t, 0, 0);
	horizontal_line(pos, angle);
	return ;
}
