/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/22 14:43:42 by artgirar         ###   ########.fr       */
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
	//printf("%f\n%f\n%f\n", xs, ys, hypo);
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
	//printf("%f\n%f\n%f\n", xs, ys, hypo);
	(void)data;
	(void)p_pos;
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	horizontal_line(data, pos, angle);
	printf("\n");
	vertical_line(data, pos, angle);
	return ;
}
