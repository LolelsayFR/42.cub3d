/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:25:33 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 16:33:30 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	draw_map(t_c3_data *data, int x, int y)
{
	t_trigo	math;

	math = trigo(data, PLAYER_SIZE / 2, PLAYER_SIZE / 2);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->map_base, x, y);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->map_pangle,
		(data->player->pos.x - PLAYER_SIZE / 2) + x + math.opo,
		(data->player->pos.y - PLAYER_SIZE / 2) + y + math.adj);
	mlx_put_image_to_window(data->mlx, data->win,
		data->textures->map_player,
		(data->player->pos.x - PLAYER_SIZE / 2) + x,
		(data->player->pos.y - PLAYER_SIZE / 2) + y);
}

static void	map_put_tiles(int x, int y, t_c3_data *data, long long color)
{
	int	i;
	int	ii;

	i = 0;
	while (i++ < TILE_SIZE)
	{
		ii = 0;
		while (ii++ < TILE_SIZE)
			img_pix_put(data->textures->map_base,
				x * TILE_SIZE - i + TILE_SIZE,
				y * TILE_SIZE - ii + TILE_SIZE, color);
	}
}

void	create_minimap_img(t_c3_data *data)
{
	int	x;
	int	y;

	data->textures->map_base = img_new(data->map_size[1] * TILE_SIZE,
			data->map_size[0] * TILE_SIZE, data);
	img_put_bg(data->textures->map_base, DARKRED_PIXEL);
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				map_put_tiles(x, y, data, WHITE_PIXEL);
			else if (data->map[y][x] == '0')
				map_put_tiles(x, y, data, GREY_PIXEL);
			else if (ft_strchr("NSOW", data->map[y][x]) != NULL)
				map_put_tiles(x, y, data, GREEN_PIXEL);
			x++;
		}
		y++;
	}
}
