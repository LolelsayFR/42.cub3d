/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_trigo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:02:32 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 05:21:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_trigo	trigo(double *angle, double x, double y)
{
	t_trigo	math;

	if (*angle >= 360)
		*angle -= 360;
	else if (*angle < 0)
		*angle += 360;
	math.angle_rad = *angle * (N_PI / 180.0);
	math.hypo = hypot(x, y);
	math.opo = math.hypo * sin(math.angle_rad);
	math.adj = math.hypo * cos(math.angle_rad);
	return (math);
}

void	raytrigo(t_ray *ray, double dist, t_pos pos)
{
	t_trigo	math;

	math.angle_rad = ray->angle;
	math.hypo = hypot(dist, 0);
	ray->old_pos = ray->pos;
	ray->pos.x = pos.x + math.hypo * sin(ray->angle);
	ray->pos.y = pos.y + math.hypo * cos(ray->angle);
}
