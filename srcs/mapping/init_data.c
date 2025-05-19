/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:40:46 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 10:55:46 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_c3_data	*data_init(void)
{
	t_c3_data	*data;

	data = malloc(sizeof(t_c3_data));
	data->textures = malloc(sizeof(t_textures));
	data->player = malloc(sizeof(t_player));
	return (data);
}
