/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_stocking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:21:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/04 06:37:49 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	doors_stocking(t_c3_data **data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	(*data)->map_door_matrix = ft_calloc((*data)->map_size[0] + 1,
			sizeof(t_door **));
	while (i <= (*data)->map_size[0])
		(*data)->map_door_matrix[i++] = ft_calloc((*data)->map_size[1] + 1,
				sizeof(t_door *));
	{
		x = 0;
		while ((*data)->map[y][x] != '\0')
		{
			if ((*data)->map[y][x] == 'D' && y > 0 && x > 0)
				(*data)->map_door_matrix[y][x].c = (*data)->map[y][x];
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
