/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/22 14:14:44 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	vertical_line(t_c3_data *data, t_pos p_pos, double p_ang)
{
	double	ys;     
	double	xs;
	double	hypo;

	ys = 1;
	xs = ys / p_ang;
	hypo = hypot(xs, ys);
	printf("%f\n%f\n%f\n", xs, ys, hypo);
	(void)data;
	(void)p_pos;
}

void	horizontal_line(t_c3_data *data, t_pos p_pos, double p_ang)
{
	double	ys;
	double	xs;
	double	hypo;

	xs = 1;
        ys = xs / p_ang;
        hypo = hypot(ys, xs);
        printf("%f\n%f\n%f\n", xs, ys, hypo);
	(void)data;
	(void)p_pos;
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->floor_t, 0, HEIGHT / 2);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->ceiling_t, 0, 0);
	horizontal_line(data, pos, angle);
	printf("\n");
	vertical_line(data, pos, angle);
	return ;
}
