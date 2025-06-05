/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_using.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:05:52 by artgirar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/06/05 10:56:15 by artgirar         ###   ########.fr       */
=======
/*   Updated: 2025/06/05 11:40:18 by emaillet         ###   ########.fr       */
>>>>>>> 09df6e1 (Fix some visual and start to work in door_clock optimisation)
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	door_update(t_c3_data *d, t_pos pos, t_door *door)
{
	if (door == NULL)
		return ;
	if ((int)pos.y == (int)door->pos.y && door->anim <= 0.6
		&& (int)pos.x == (int)door->pos.x)
		return ;
	if (door->open == true
		&& door->is_anim == true && door->anim < 0.95)
		door->anim += 0.05;
	else if (door->open == false
		&& door->is_anim == true && door->anim > 0)
		door->anim -= 0.05;
	if (door->anim < 0)
		door->anim = 0;
	if (door->anim > 0.95)
		door->anim = 0.95;
	if (door->anim == 0
		&& door->open == false && door->anim == false)
	{
		d->map[(int)door->pos.y][(int)door->pos.x] = 'D';
		create_minimap_img(d);
	}
}

void	door_clock(t_c3_data *d, t_pos pos)
{
	t_pos	temp;
	t_door	*door;
	int		x;
	int		y;

	y = -DOOR_DIST;
	while (y++ <= DOOR_DIST)
	{
		temp.y = (int)(pos.y + y);
		x = -DOOR_DIST;
		while (x++ <= DOOR_DIST)
		{
			temp.x = (int)(pos.x + x);
			if (temp.x >= 0 && temp.y >= 0
				&& temp.x < d->map_size[1] && temp.y < d->map_size[0]
				&& ft_strchr("dD", d->map[(int)temp.y][(int)temp.x]))
			{
				door = get_door_data(d, temp);
				door_update(d, pos, door);
			}
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
