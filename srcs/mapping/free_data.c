/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:47:29 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 19:41:57 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	destroy_all_image(t_c3_data *data)
{
	if (data->textures->north != NULL)
		mlx_destroy_image(data->mlx, data->textures->north);
	if (data->textures->south != NULL)
		mlx_destroy_image(data->mlx, data->textures->south);
	if (data->textures->west != NULL)
		mlx_destroy_image(data->mlx, data->textures->west);
	if (data->textures->east != NULL)
		mlx_destroy_image(data->mlx, data->textures->east);
}

void	free_data(t_c3_data *data)
{
	destroy_all_image(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_strtab(data->map);
	free(data->player->control);
	free(data->player);
	free(data->textures);
	free(data->mlx);
	free(data);
}
