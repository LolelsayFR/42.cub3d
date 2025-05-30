/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_using.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:05:52 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/27 10:44:46 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	door_using(t_c3_data *data)
{
	t_pos	pos;
	t_ray	ray;
	char	**map;

	map = data->map;
	ray.dist = 0;
	pos = pos_to_map_pos(data->player->pos.x, data->player->pos.y);
	ft_bzero(&ray, sizeof(t_ray));
	ray.angle = data->player->angle * (N_PI / 180.0);
	while (ft_strchr("Dd", map[(int)ray.pos.y][(int)ray.pos.x]) == NULL
			&& ray.dist <= USE_RANGE)
	{
		raytrigo(&ray, ray.dist, pos);
		ray.dist += RAY_PRECISION;
	}
	if (ft_strchr("Dd", map[(int)pos.y][(int)pos.x]) != NULL)
		return ;
	if (map[(int)ray.pos.y][(int)ray.pos.x] == 'D')
		map[(int)ray.pos.y][(int)ray.pos.x] = 'd';
	else if (map[(int)ray.pos.y][(int)ray.pos.x] == 'd')
		map[(int)ray.pos.y][(int)ray.pos.x] = 'D';
}
