/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_using.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:05:52 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/06 01:44:31 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static bool	inmap(t_c3_data *data, t_pos pos)
{
	if ((int)pos.x < 0 || pos.y < 0
		|| (int)pos.x >= data->map_size[1] || pos.y >= data->map_size[0])
		return (false);
	if ((int)pos.x > (int)ft_strlen(data->map[(int)pos.y]))
		return (false);
	return (true);
}

static void	door_update(t_c3_data *d, t_pos pos, t_door *door)
{
	if (door == NULL)
		return ;
	if ((int)pos.y == (int)door->pos.y && door->anim <= 0.6
		&& (int)pos.x == (int)door->pos.x && !door->open)
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
	while (y <= DOOR_DIST)
	{
		x = -DOOR_DIST;
		while (x <= DOOR_DIST)
		{
			temp.y = (int)(pos.y + y);
			temp.x = (int)(pos.x + x);
			if (inmap(d, temp)
				&& d->map[(int)temp.y]
				[(int)temp.x] == 'd')
			{
				door = get_door_data(d, temp);
				if (door != NULL)
					door_update(d, pos, door);
			}
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
		doortrigo(&ray, ray.dist, pos);
		ray.dist += RAY_PRECISION;
		while ((int)pos.y == (int)ray.pos.y && (int)pos.x == (int)ray.pos.x)
		{
			doortrigo(&ray, ray.dist, pos);
			ray.dist += RAY_PRECISION;
		}
	}
	if ((int)pos.y == (int)ray.pos.y && (int)pos.x == (int)ray.pos.x)
		return ;
	door_toggle(data, ray);
}
