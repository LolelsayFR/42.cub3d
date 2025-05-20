/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:45:17 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/20 12:51:50 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	is_not_walled(t_c3_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (ft_strchr("0NSWE", data->map[y][x]) != NULL)
				if (finds_next_value(data, x, y, ft_strlen(data->map[y])) == -1)
					return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	charset_is_correct(t_c3_data *data)
{
	int	x;
	int	y;
	int	numb_player;

	numb_player = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (ft_strchr("10NSEW ", data->map[y][x]) == NULL)
				return (-1);
			if (ft_strchr("NSEW", data->map[y][x]) != NULL)
				numb_player++;
			x++;
		}
		y++;
	}
	if (numb_player == 0 || numb_player > 1)
		return (-1);
	return (0);
}

int	ext_is_correct(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map[i] != '\0')
		i++;
	i -= 4;
	if (i < 0)
		return (-1);
	if (ft_strncmp(&map[i], ".cub", 4) != 0)
		return (-1);
	return (0);
}
