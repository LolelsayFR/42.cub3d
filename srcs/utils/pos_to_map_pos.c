/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_to_map_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:31:55 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 15:36:03 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_pos	pos_to_map_pos(double x, double y)
{
	t_pos	pos;

	pos.y = (y / TILE_SIZE);
	pos.x = (x / TILE_SIZE);
	return (pos);
}
