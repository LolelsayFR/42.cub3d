/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 16:34:41 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	(void)pos;
	(void)angle;
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->floor_t, 0, HEIGHT / 2);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->ceiling_t, 0, 0);
	return ;
}
