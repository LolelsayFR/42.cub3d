/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_using.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:05:52 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/04 23:57:55 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	door_update(t_c3_data *d, int x, int y, t_door *doors)
{
	if (doors == NULL)
		return ;
	if (y == (int)doors->pos.y && doors->anim <= 0.6
		&& x == (int)doors->pos.x)
		return ;
	if (doors->open == true
		&& doors->is_anim == true && doors->anim < 0.95)
		doors->anim += 0.05;
	else if (doors->open == false
		&& doors->is_anim == true && doors->anim > 0)
		doors->anim -= 0.05;
	if (doors->anim < 0)
		doors->anim = 0;
	if (doors->anim > 0.95)
		doors->anim = 0.95;
	if (doors->anim == 0
		&& doors->open == false && doors->is_anim == false)
	{
		d->map[(int)doors->pos.y][(int)doors->pos.x] = 'D';
		create_minimap_img(d);
	}
}

void	door_clock(t_c3_data *d, t_pos pos)
{
	t_pos	temp;
	int		x;
	int		y;

	y = -DOOR_DIST;
	while (y <= DOOR_DIST)
	{
		x = -DOOR_DIST;
		while (x <= DOOR_DIST)
		{
			temp.x = (int)(pos.x + x);
			temp.y = (int)(pos.y + y);
			if (temp.x > 0 && temp.y > 0
				&& temp.x < d->map_size[1] && temp.y < d->map_size[0]
				&& ft_strchr("dD", d->map[(int)temp.y][(int)temp.x]))
				door_update(d, pos.x, pos.y, get_door_data(d, temp));
			x++;
		}
		y++;
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
