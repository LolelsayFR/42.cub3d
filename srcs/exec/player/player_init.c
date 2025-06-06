/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:44:50 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/06 09:59:13 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	player_setspawn(t_c3_data *data)
{
	int	p[2];

	p[1] = 0;
	p[0] = 0;
	while (data->map[p[0]] != NULL)
	{
		p[1] = 0;
		while (data->map[p[0]][p[1]] != '\0' && data->map[p[0]][p[1]] != '\n')
		{
			if (ft_strchr("NSEW", data->map[p[0]][p[1]]) != NULL)
				break ;
			p[1]++;
		}
		if (ft_strchr("NSEW", data->map[p[0]][p[1]]) != NULL)
			break ;
		p[0]++;
	}
	if (data->map[p[0]][p[1]] == 'N')
		data->player->angle = 180;
	else if (data->map[p[0]][p[1]] == 'E')
		data->player->angle = 90;
	else if (data->map[p[0]][p[1]] == 'W')
		data->player->angle = -90;
	data->player->pos.y = ((p[0] + 1) * TILE_SIZE) - (TILE_SIZE / 2);
	data->player->pos.x = ((p[1] + 1) * TILE_SIZE) - (TILE_SIZE / 2);
}

bool	player_init(t_c3_data *data)
{
	data->textures->map_pangle = img_new(PLAYER_SIZE, PLAYER_SIZE, data);
	data->textures->map_player = img_new(PLAYER_SIZE, PLAYER_SIZE, data);
	img_put_bg(data->textures->map_pangle, darker_rgb(GREEN_PIXEL, 8));
	img_put_bg(data->textures->map_player, GREEN_PIXEL);
	player_setspawn(data);
	return (true);
}
