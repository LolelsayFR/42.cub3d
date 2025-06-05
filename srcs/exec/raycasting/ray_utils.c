/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:16:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/05 13:17:25 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

bool	ray_strchr(char *set, t_c3_data *data, t_ray ray)
{
	if ((ft_strchr(set, data->map[(int)ray.pos.y][(int)ray.old_pos.x])
		|| ft_strchr(set, data->map[(int)ray.old_pos.y][(int)ray.pos.x])
	|| ft_strchr(set, data->map[(int)ray.pos.y][(int)ray.pos.x])))
		return (true);
	return (false);
}
