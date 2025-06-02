/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_stocking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:21:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/02 18:35:50 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	inside_stock(t_c3_data **data)
{
	int	x;
	int	y;

	y = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == 'D')
			{
				(*data)->doors->pos.x = x;
				(*data)->doors->pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	doors_stocking(t_c3_data **data)
{
	int	x;
	int	y;
	int	nb_doors;

	y = 0;
	nb_doors = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
			if ((*data)->map[y][x++] == 'D')
				nb_doors++;
		y++;
	}
	(*data)->doors = ft_calloc(nb_doors, sizeof(t_door));
	inside_stock(data);
}
