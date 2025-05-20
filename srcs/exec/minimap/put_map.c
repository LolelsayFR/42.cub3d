/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:25:33 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 15:45:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	map_put_tiles(int x, int y, t_c3_data *data, long long color)
{
	int	i;
	int	ii;

	i = 0;
	while (i++ < MINIMAP_TILE)
	{
		ii = 0;
		while (ii++ < MINIMAP_TILE)
			img_pix_put(data->textures->map_base,
				x * MINIMAP_TILE - i + MINIMAP_TILE + 10,
				y * MINIMAP_TILE - ii + MINIMAP_TILE + 10, color);
	}
}

// static void	map_put_player(int x, int y, t_c3_data *data, long long color)
// {
// 	int	i;
// 	int	ii;

// 	i = 0;
// 	while (i++ < MINIMAP_TILE)
// 	{
// 		ii = 0;
// 		while (ii++ < MINIMAP_TILE)
// 			img_pix_put(data->textures->map_base,
// 				x * MINIMAP_TILE - i + MINIMAP_TILE + 10,
// 				y * MINIMAP_TILE - ii + MINIMAP_TILE + 10, color);
// 	}
// }

// void	create_miniplayer_img(t_c3_data *data)
// {
// 	int	x;
// 	int	y;

// 	data->textures->map_base = img_new(data->map_size[1] * MINIMAP_TILE + 20,
// 			data->map_size[0] * MINIMAP_TILE + 20, data);
// 			if (ft_strchr("NSOW", data->map[y][x]) != NULL)
// 				map_put_tiles(x, y, data, GREEN_PIXEL);
// 	}
// 	data->winmap = mlx_new_window(data->mlx, (data->map_size[1] * MINIMAP_TILE),
// 			(data->map_size[0] * MINIMAP_TILE), "Cub3D Map");
// }

void	create_minimap_img(t_c3_data *data)
{
	int	x;
	int	y;

	data->textures->map_base = img_new(data->map_size[1] * MINIMAP_TILE + 20,
			data->map_size[0] * MINIMAP_TILE + 20, data);
	img_put_background(data->textures->map_base, DARKRED_PIXEL);
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				map_put_tiles(x, y, data, BLACK_PIXEL);
			else if (data->map[y][x] == '0')
				map_put_tiles(x, y, data, GREY_PIXEL);
			else if (ft_strchr("NSOW", data->map[y][x]) != NULL)
				map_put_tiles(x, y, data, GREEN_PIXEL);
			x++;
		}
		y++;
	}
	data->winmap = mlx_new_window(data->mlx,
			(data->map_size[1] * MINIMAP_TILE + 20),
			(data->map_size[0] * MINIMAP_TILE + 20), "Cub3D Map");
}
