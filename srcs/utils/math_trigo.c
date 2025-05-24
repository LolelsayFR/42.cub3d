/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_trigo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:02:32 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/24 21:35:24 by emaillet         ###   ########.fr       */
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

t_trigo	raytrigo(double angle, double x, double y)
{
	t_trigo	math;

	if (angle >= 360)
		angle -= 360;
	else if (angle < 0)
		angle += 360;
	math.angle_rad = angle * (N_PI / 180.0);
	math.hypo = hypot(x, y);
	math.opo = math.hypo * sin(math.angle_rad);
	math.adj = math.hypo * cos(math.angle_rad);
	return (math);
}
