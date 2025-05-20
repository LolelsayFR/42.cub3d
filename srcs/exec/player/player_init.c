/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:50 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 17:33:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	player_setspawn(t_c3_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
		{
			if (ft_strchr("NSEW", data->map[y][x]) != NULL)
				break ;
			x++;
		}
		if (ft_strchr("NSEW", data->map[y][x]) != NULL)
			break ;
		y++;
	}
	data->spawn[0] = y + 1;
	data->spawn[1] = x + 1;
	data->player->pos[0] = (data->spawn[0] * MINIMAP_TILE) - (MINIMAP_TILE / 2);
	data->player->pos[1] = (data->spawn[1] * MINIMAP_TILE) - (MINIMAP_TILE / 2);
	ft_printf(YEL"Spawn : x = %d y = %d"RES, data->spawn[1], data->spawn[0]);
}

bool	player_init(t_c3_data *data)
{
	player_setspawn(data);
	return (true);
}
