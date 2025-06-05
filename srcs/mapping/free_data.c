/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:47:29 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/04 05:59:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	destroy_all_image(t_c3_data *data)
{
	if (data->textures->map_base != NULL)
		mlx_destroy_image(data->mlx, data->textures->map_base);
	if (data->textures->map_player != NULL)
		mlx_destroy_image(data->mlx, data->textures->map_player);
	if (data->textures->map_pangle != NULL)
		mlx_destroy_image(data->mlx, data->textures->map_pangle);
	if (data->textures->door != NULL)
		mlx_destroy_image(data->mlx, data->textures->door);
	if (data->textures->north != NULL)
		mlx_destroy_image(data->mlx, data->textures->north);
	if (data->textures->south != NULL)
		mlx_destroy_image(data->mlx, data->textures->south);
	if (data->textures->west != NULL)
		mlx_destroy_image(data->mlx, data->textures->west);
	if (data->textures->east != NULL)
		mlx_destroy_image(data->mlx, data->textures->east);
	if (data->frame != NULL)
		mlx_destroy_image(data->mlx, data->frame);
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
