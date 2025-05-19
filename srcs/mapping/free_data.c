/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:47:29 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 17:45:50 by emaillet         ###   ########.fr       */
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
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free_strtab(data->map);
	free(data->player);
	free(data->textures);
	free(data->mlx);
	free(data);
}
