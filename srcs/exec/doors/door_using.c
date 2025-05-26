/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_using.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 09:05:52 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/26 09:19:40 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	door_using(t_c3_data *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->map;
	x = (int)data->player->pos.x / TILE_SIZE;
	y = (int)data->player.y / TILE_SIZE;
}
