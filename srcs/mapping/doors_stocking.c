/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_stocking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:21:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/04 23:01:34 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	inside_stock(t_c3_data **data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == 'D' && i <= (*data)->n_doors)
			{
				(*data)->doors[i].pos.x = x;
				(*data)->doors[i].pos.y = y;
				i++;
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

	(*data)->map_door_link = ft_strtabdup_lst((*data)->map);
	y = 0;
	nb_doors = 0;
	while ((*data)->map[y] != NULL)
	{
		x = 0;
		while ((*data)->map[y][x++] != '\0')
			if ((*data)->map[y][x] == 'D')
				(*data)->map_door_link[y][x] = nb_doors++;
		else
			(*data)->map_door_link[y][x] = 0;
		y++;
	}
	(*data)->n_doors = nb_doors;
	(*data)->doors = ft_calloc(nb_doors + 1, sizeof(t_door));
	inside_stock(data);
}
