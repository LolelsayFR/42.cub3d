/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:35:10 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 06:34:35 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_door	*get_door_data(t_c3_data *data, t_pos pos)
{
	t_door	*result;
	int		x;
	int		y;

	y = (int)pos.y;
	x = (int)pos.x;
	if (!data || !data->map_door_matrix || !data->map)
		return (NULL);
	if (y < 0 || x < 0 || !data->map_door_matrix[y] || !data->map[y])
		return (NULL);
	result = &data->map_door_matrix[y][x];
	if (result->c == 0)
		return (NULL);
	door_update(data, pos, result);
	return (result);
}
