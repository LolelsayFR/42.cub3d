/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:35:10 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/05 21:58:53 by emaillet         ###   ########.fr       */
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

t_door	*get_door_data(t_c3_data *data, t_pos pos)
{
	t_door	*result;
	int		i;

	i = 0;
	if (!inmap(data, pos))
		return (NULL);
	while (i <= data->n_doors
		&& !((int)data->doors[i].pos.x == (int)pos.x
			&& (int)data->doors[i].pos.y == (int)pos.y))
		i++;
	if (i > data->n_doors)
		return (NULL);
	result = &data->doors[i];
	return (result);
}
