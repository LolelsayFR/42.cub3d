/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:40:14 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/29 13:31:57 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	door_ray_assign(int x, t_c3_data *data)
{
	int	l;

	data->ray[x]->save_pos = data->ray[x]->pos;
	data->ray[x]->door_count++;
	l = data->ray[x]->door_count;
	data->ray[x][l].dist = data->ray[x][0].exec_dist
		* cos(data->ray[x][0].angle - (data->player->angle * (N_PI / 180.0)));
	data->ray[x][l].pos = data->ray[x][0].pos;
	data->ray[x][l].old_pos = data->ray[x][0].old_pos;
	if (data->map[(int)data->ray[x][l].pos.y]
			[(int)data->ray[x][l].pos.x] == 'D')
	{
		data->ray[x][l].texture = data->textures->door;
		data->ray[x][l].color = darker_rgb(C_DOORS, data->ray[x][l].dist);
		data->ray[x][l].shift_up = 0; // change value to anim
	}
	else if (data->map[(int)data->ray[x][l].pos.y]
			[(int)data->ray[x][l].pos.x] == 'd')
	{
		data->ray[x][l].texture = data->textures->door;
		data->ray[x][l].color = darker_rgb(C_ODOORS, data->ray[x][l].dist);
		data->ray[x][l].shift_up = 0.8;
	}
}

static void	wall_ray_assign(int x, t_c3_data *data)
{
	if ((int)data->ray[x]->old_pos.y > (int)data->ray[x]->pos.y)
	{
		data->ray[x]->texture = data->textures->north;
		data->ray[x]->color = darker_rgb(C_N_WALL, data->ray[x]->exec_dist);
	}
	else if ((int)data->ray[x]->old_pos.x > (int)data->ray[x]->pos.x)
	{
		data->ray[x]->texture = data->textures->west;
		data->ray[x]->color = darker_rgb(C_W_WALL, data->ray[x]->exec_dist);
	}
	else if ((int)data->ray[x]->old_pos.y < (int)data->ray[x]->pos.y)
	{
		data->ray[x]->texture = data->textures->south;
		data->ray[x]->color = darker_rgb(C_S_WALL, data->ray[x]->exec_dist);
	}
	else if ((int)data->ray[x]->old_pos.x < (int)data->ray[x]->pos.x)
	{
		data->ray[x]->texture = data->textures->east;
		data->ray[x]->color = darker_rgb(C_E_WALL, data->ray[x]->exec_dist);
	}
}

static void	ray_colider(t_c3_data *data, int x, t_pos pos)
{
	while ((int)data->ray[x]->pos.y < data->map_size[0]
		&& (int)data->ray[x]->pos.x < data->map_size[1]
		&& (int)data->ray[x]->pos.y >= 0 && (int)data->ray[x]->pos.x >= 0
		&& !ft_strchr("\n 1\0",
			data->map[(int)data->ray[x]->pos.y][(int)data->ray[x]->pos.x]))
	{
		if (ft_strchr("Dd",
				data->map[(int)data->ray[x]->pos.y][(int)data->ray[x]->pos.x])
			&& (int)data->ray[x]->save_pos.x != (int)data->ray[x]->pos.x
			&& (int)data->ray[x]->save_pos.y != (int)data->ray[x]->pos.y)
			door_ray_assign(x, data);
		data->ray[x]->old_pos = data->ray[x]->pos;
		data->ray[x]->exec_dist += RAY_PRECISION + (data->ray[x]->dist / 100);
		raytrigo(data->ray[x], data->ray[x]->exec_dist, pos);
		if (ft_strchr("\n 1\0", data->map[(int)data->ray[x]->old_pos.y]
				[(int)data->ray[x]->pos.x])
			|| ft_strchr("\n 1\0", data->map[(int)data->ray[x]->pos.y]
				[(int)data->ray[x]->old_pos.x]))
			break ;
	}
	wall_ray_assign(x, data);
}

static void	copy_all_layer(int x, t_c3_data *data)
{
	int	l;

	data->ray[x][0] = data->ray[x - 1][0];
	l = data->ray[x - 1][0].door_count;
	while (l > 0)
	{
		data->ray[x][l] = data->ray[x - 1][l];
		l--;
	}
}

void	wall_raycasting(t_c3_data *data, t_pos pos, double angle)
{
	int		x;

	x = 0;
	angle = angle * (N_PI / 180.0);
	while (x < WIDTH)
	{
		if (x % RAY_DIVIDER == 0)
		{
			ft_bzero(data->ray[x], sizeof(t_ray) * RENDER_DIST);
			data->ray[x][0].angle = angle - (FOV / 2.0) * (N_PI / 180.0)
				+ ((double)x / WIDTH) * FOV * (N_PI / 180.0);
			raytrigo(data->ray[x], data->ray[x][0].exec_dist, pos);
			data->ray[x][0].pos = pos;
			data->ray[x][0].old_pos = data->ray[x][0].pos;
			ray_colider(data, x, pos);
			data->ray[x][0].dist = data->ray[x][0].exec_dist
				* cos(data->ray[x][0].angle - angle);
		}
		else if (x > 0)
			copy_all_layer(x, data);
		frame_put_layers_ray(x, data);
		x++;
	}
}
