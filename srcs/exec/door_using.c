/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_using.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:05:52 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/04 04:13:27 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	door_clock(t_c3_data *d, t_pos pos)
{
	int		i;

	i = -1;
	while (++i < d->n_doors)
	{
		if ((int)pos.y == (int)d->doors[i].pos.y && d->doors[i].anim <= 0.6
			&& (int)pos.x == (int)d->doors[i].pos.x)
			continue ;
		if (d->doors[i].open == true
			&& d->doors[i].is_anim == true && d->doors[i].anim < 0.95)
			d->doors[i].anim += 0.05;
		else if (d->doors[i].open == false
			&& d->doors[i].is_anim == true && d->doors[i].anim > 0)
			d->doors[i].anim -= 0.05;
		if (d->doors[i].anim < 0)
			d->doors[i].anim = 0;
		if (d->doors[i].anim > 0.95)
			d->doors[i].anim = 0.95;
		if (d->doors[i].anim == 0
			&& d->doors[i].open == false && d->doors[i].anim == false)
		{
			d->map[(int)d->doors[i].pos.y][(int)d->doors[i].pos.x] = 'D';
			create_minimap_img(d);
		}
	}
}

static void	door_toggle(t_c3_data *data, t_ray ray)
{
	t_door	*door;

	door = get_door_data(data, ray.pos);
	if (door == NULL)
		return ;
	if (door->open == true)
	{
		door->is_anim = true;
		door->open = false;
	}
	else if (door->open == false)
	{
		data->map[(int)ray.pos.y][(int)ray.pos.x] = 'd';
		door->is_anim = true;
		door->open = true;
	}
	create_minimap_img(data);
}

void	door_using(t_c3_data *data)
{
	t_pos	pos;
	t_ray	ray;
	char	**map;

	map = data->map;
	pos = pos_to_map_pos(data->player->pos.x, data->player->pos.y);
	ft_bzero(&ray, sizeof(t_ray));
	ray.angle = data->player->angle * (N_PI / 180.0);
	while (ft_strchr("Dd", map[(int)ray.pos.y][(int)ray.pos.x]) == NULL
			&& ray.dist <= USE_RANGE)
	{
		raytrigo(&ray, ray.dist, pos);
		ray.dist += RAY_PRECISION;
		while ((int)pos.y == (int)ray.pos.y && (int)pos.x == (int)ray.pos.x)
		{
			raytrigo(&ray, ray.dist, pos);
			ray.dist += RAY_PRECISION;
		}
	}
	if ((int)pos.y == (int)ray.pos.y && (int)pos.x == (int)ray.pos.x)
		return ;
	door_toggle(data, ray);
}
