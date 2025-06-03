/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_door_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:35:10 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/03 13:32:57 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_door	*get_door_data(t_c3_data *data, t_pos pos)
{
	t_door	*result;
	int		i;

	i = 0;
	while (i <= data->n_doors
		&& !((int)data->doors[i].pos.x == (int)pos.x
			&& (int)data->doors[i].pos.y == (int)pos.y))
		i++;
	result = &data->doors[i];
	return (result);
}
