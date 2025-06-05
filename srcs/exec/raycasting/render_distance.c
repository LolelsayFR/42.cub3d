/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 01:46:46 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/06 01:47:17 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

bool	render_distance(t_c3_data *data)
{
	if (data->ray.exec_dist < RENDER_DIST)
	{
		data->ray.texture = NULL;
		data->ray.color = BLACK_PIXEL;
		return (true);
	}
	return (false);
}
