/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_trigo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:02:32 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 13:08:55 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"


t_trigo	trigo(t_c3_data *data, int x, int y)
{
	t_trigo	math;

	if (data->player->angle >= 360)
		data->player->angle -= 360;
	else if (data->player->angle < 0)
		data->player->angle += 360;
	math.angle_rad = data->player->angle * (N_PI / 180.0);
	math.hypo = hypot(x, y);
	math.opo = math.hypo * sin(math.angle_rad);
	math.adj = math.hypo * cos(math.angle_rad);
	return (math);
}
