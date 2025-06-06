/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:40:46 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/06 00:08:18 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_c3_data	*data_init(void)
{
	t_c3_data	*data;

	data = ft_calloc(1, sizeof(t_c3_data));
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		data->exit_status = 2;
		game_close(data);
	}
	data->textures = ft_calloc(1, sizeof(t_textures));
	data->player = ft_calloc(1, sizeof(t_player));
	data->player->control = ft_calloc(1, sizeof(t_control));
	return (data);
}
