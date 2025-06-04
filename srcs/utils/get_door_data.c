/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:35:10 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 23:02:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_door	*get_door_data(t_c3_data *data, t_pos pos)
{
	t_door	*result;
	int		i;

	if (data->map_door_link[(int)pos.y][(int)pos.x] == 0)
		return (NULL);
	i = data->map_door_link[(int)pos.y][(int)pos.x];
	if (i > data->n_doors)
		return (NULL);
	result = &data->doors[i];
	return (result);
}
