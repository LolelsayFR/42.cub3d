/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_stocking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:21:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/03 12:31:30 by emaillet         ###   ########.fr       */
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
	(*data)->n_doors = nb_doors;
	(*data)->doors = ft_calloc(nb_doors + 1, sizeof(t_door));
	inside_stock(data);
}
