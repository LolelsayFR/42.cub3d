/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:34:37 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 23:06:38 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.define.h"

void	map_size(t_c3_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = fmaxl(x, ft_strlen(data->map[y]));
		y++;
	}
	data->map_size[0] = y;
	data->map_size[1] = x - 1;
	ft_printf(YEL"Map size : x = %d, y = %d"RES, data->map_size[1],
		data->map_size[0]);
}
