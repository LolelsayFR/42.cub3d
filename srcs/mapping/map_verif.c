/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:45:17 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 17:26:24 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	is_not_walled(t_c3_data *data)
{
	int	x;
	int	y;

	//find_start(&x, &y);
	return ((void)x, (void)y, (void)data, 0);
}

int	charset_is_correct(char **map)
{
	int	x;
	int	y;
	int	numb_player;

	numb_player = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (ft_strchr("10NSEW ", map[y][x]) == NULL)
				return (-1);
			if (ft_strchr("NSEW", map[y][x]) != NULL)
				numb_player++;
			x++;
		}
		y = 0;
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
