/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:37:57 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 18:55:20 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	finds_next_value(t_c3_data *data, int x, int y)
{
	int	i;
	int	j;

	find_max(data->map, &i, &j);
	if (x == 0 || y == 0 || x == i || y == j)
		return (-1);
	if (ft_strchr("01NSEW", data->map[y][x + 1]) == NULL)
		return (-1);
	if (ft_strchr("01NSEW", data->map[y + 1][x]) == NULL)
                return (-1);
	if (ft_strchr("01NSEW", data->map[y][x - 1]) == NULL)
                return (-1);
	if (ft_strchr("01NSEW", data->map[y - 1][x]) == NULL)
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
