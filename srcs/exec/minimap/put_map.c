/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 00:25:33 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 00:28:14 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	put_whitesqare(int x, int y, int size, t_c3_data *data)
{
	int	i;
	int	ii;

	i = 0;
	while (i++ < size)
	{
		ii = 0;
		while (ii++ < size)
			mlx_pixel_put(data->mlx, data->win,
				x * size - i + size,
				y * size - ii + size, 0xFFFFFFFF);
	}
}

void	put_greysqare(int x, int y, int size, t_c3_data *data)
{
	int	i;
	int	ii;

	i = 0;
	while (i++ < size)
	{
		ii = 0;
		while (ii++ < size)
			mlx_pixel_put(data->mlx, data->win,
				x * size - i + size,
				y * size - ii + size, 0x42424242);
	}
}

void	put_greensqare(int x, int y, int size, t_c3_data *data)
{
	int	i;
	int	ii;

	i = 0;
	while (i++ < size)
	{
		ii = 0;
		while (ii++ < size)
			mlx_pixel_put(data->mlx, data->win,
				x * size - i + size,
				y * size - ii + size, 0x00F000);
	}
}

//Pour le moment je fait un putpixel de la map, a therme je ferais 
//	une image pre charger afin de rendre cela plus performant
void	put_map(t_c3_data *data)
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
				put_whitesqare(x, y, 25, data);
			else if (data->map[y][x] == '0')
				put_greysqare(x, y, 25, data);
			else if (ft_strchr("NSOW", data->map[y][x]) != NULL)
				put_greensqare(x, y, 25, data);
			x++;
		}
		y++;
	}
}
