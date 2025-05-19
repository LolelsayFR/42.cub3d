/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:47:29 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 16:52:07 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	destroy_all_image(t_c3_data *data)
{
	mlx_destroy_image(data->mlx, data->textures->north);
	mlx_destroy_image(data->mlx, data->textures->south);
	mlx_destroy_image(data->mlx, data->textures->west);
	mlx_destroy_image(data->mlx, data->textures->east);
}

void	free_data(t_c3_data *data)
{
	destroy_all_image(data);
	ft_free_strtab(data->map);
	free(data->player);
	free(data->textures);
	free(data->mlx);
	free(data);
}
