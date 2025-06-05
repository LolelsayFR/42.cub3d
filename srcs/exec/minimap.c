/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:25:33 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/05 11:36:03 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	put_my_map(t_c3_data *data, t_img *img, int x, int y)
{
	GC			gc;

	gc = data->win->gc;
	if (img->gc)
	{
		gc = img->gc;
		XSetClipOrigin(data->mlx->display, gc, x, y);
	}
	if (img->type == MLX_TYPE_SHM)
		XShmPutImage(data->mlx->display, img->pix, data->win->gc, img->image,
			0, 0, 0, 0, img->width, img->height, False);
	XCopyArea(data->mlx->display, img->pix, data->win->window, gc,
		data->player->pos.x - MINIMAP_SIZE / 2,
		data->player->pos.y - MINIMAP_SIZE / 2, MINIMAP_SIZE,
		MINIMAP_SIZE, x, y);
	if (data->mlx->do_flush)
		XFlush(data->mlx->display);
}

static void	draw_all_map(t_c3_data *data, int x, int y, t_trigo	math)
{
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

void	draw_map(t_c3_data *data, int x, int y)
{
	t_trigo	math;

	math = trigo(&data->player->angle, PLAYER_SIZE / 2, PLAYER_SIZE / 2);
	if (data->player->control->map % 4 == 0)
	{
		put_my_map(data, data->textures->map_base, x, y);
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->map_pangle,
			((MINIMAP_SIZE / 2) - PLAYER_SIZE / 2) + x + math.opo,
			((MINIMAP_SIZE / 2) - PLAYER_SIZE / 2) + y + math.adj);
		mlx_put_image_to_window(data->mlx, data->win,
			data->textures->map_player,
			((MINIMAP_SIZE / 2) - PLAYER_SIZE / 2) + x,
			((MINIMAP_SIZE / 2) - PLAYER_SIZE / 2) + y);
	}
	else if (data->player->control->map % 4 == 1)
		draw_all_map(data, x, y, math);
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
			img_pp(data->textures->map_base,
				x * TILE_SIZE - i + TILE_SIZE,
				y * TILE_SIZE - ii + TILE_SIZE, color);
	}
}

void	create_minimap_img(t_c3_data *data)
{
	int	x;
	int	y;

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
			else if (ft_strchr("NSEW", data->map[y][x]) != NULL)
				map_put_tiles(x, y, data, GREEN_PIXEL);
			else if (ft_strchr("D", data->map[y][x]) != NULL)
				map_put_tiles(x, y, data, RED_PIXEL);
			else if (ft_strchr("d", data->map[y][x]) != NULL)
				map_put_tiles(x, y, data, darker_rgb(RED_PIXEL, 10));
			x++;
		}
		y++;
	}
}
