/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:50 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 14:02:20 by emaillet         ###   ########.fr       */
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
	if (data->map[y][x] == 'N')
		data->player->angle = 180;
	else if (data->map[y][x] == 'E')
		data->player->angle = 90;
	else if (data->map[y][x] == 'W')
		data->player->angle = -90;
	data->player->pos[0] = ((y + 1) * TILE_SIZE) - (TILE_SIZE / 2);
	data->player->pos[1] = ((x + 1) * TILE_SIZE) - (TILE_SIZE / 2);
}

bool	player_init(t_c3_data *data)
{
	data->textures->map_player = img_new(PLAYER_SIZE, PLAYER_SIZE, data);
	data->textures->map_pangle = img_new(PLAYER_SIZE, PLAYER_SIZE, data);
	img_put_background(data->textures->map_pangle, RED_PIXEL);
	img_put_background(data->textures->map_player, BLUE_PIXEL);
	player_setspawn(data);
	return (true);
}
