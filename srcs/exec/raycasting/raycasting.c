/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/24 21:43:40 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static t_ray	ray_colider(t_c3_data *data, t_trigo m, t_ray ray, t_pos pos)
{
	while (data->map[(int)ray.pos.y][(int)ray.pos.x] != '1')
	{
		ray.old_pos = ray.pos;
		ray.dist += 0.01;
		m = raytrigo(ray.angle, ray.dist, 0);
		ray.pos = pos;
		ray.pos.x += m.opo;
		ray.pos.y += m.adj;
	}
	if ((int)ray.old_pos.y > (int)ray.pos.y)
		ray.dir = 'N';
	else if ((int)ray.old_pos.y < (int)ray.pos.y)
		ray.dir = 'S';
	else if ((int)ray.old_pos.x > (int)ray.pos.x)
		ray.dir = 'W';
	else if ((int)ray.old_pos.x < (int)ray.pos.x)
		ray.dir = 'E';
	if (data->map[(int)ray.pos.y][(int)ray.pos.x] == '1')
		printf("Wall point pos at x = %f y = %f Dist = %f, Dir = %c\n",
			ray.pos.x, ray.pos.y, ray.dist, ray.dir);
	return (ray);
}

void	raycasting(t_c3_data *data, t_pos pos, double angle)
{
	t_ray	ray;
	t_trigo	math;

	ray.dist = 0;
	ray.angle = angle;//  - FOV/ 2;
	math = raytrigo(ray.angle, ray.dist, 0);
	ray.pos = pos;
	ray.old_pos = ray.pos;
	ray.pos.x += math.opo;
	ray.pos.y += math.adj;
	ray_colider(data, math, ray, pos);
}
