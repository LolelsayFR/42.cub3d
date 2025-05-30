/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:37:57 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/30 19:37:19 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	finds_other_space(char *line)
{
	int	x;

	if (line == NULL)
		return (0);
	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
	{
		if (line[x] != ' ')
			return (-1);
		x++;
	}
	return (0);
}

int	finds_next_value(t_c3_data *data, int x, int y, int max)
{
	if (x == 0 || y == 0 || x == max || data->map[y + 1] == NULL
		|| ft_strchr("\0", data->map[y + 1][x]) != NULL)
		return (-1);
	if (ft_strchr("01NSEWD", data->map[y][x + 1]) == NULL)
		return (-1);
	if (ft_strchr("01NSEWD", data->map[y + 1][x]) == NULL)
		return (-1);
	if (ft_strchr("01NSEWD", data->map[y][x - 1]) == NULL)
		return (-1);
	if (ft_strchr("01NSEWD", data->map[y - 1][x]) == NULL)
		return (-1);
	return (0);
}

void	find_max(char **map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (map[*y + 1] != NULL)
		(*y)++;
	while (map[*y][*x + 1] != '\0')
		(*x)++;
}
