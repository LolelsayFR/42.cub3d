/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:40:46 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 13:33:35 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	init_rgb(t_c3_data **data, char *line, int i)
{
	char	**temp;

	temp = ft_split(line + 2, ',');
	if (ft_tablen(temp) != 3)
		return (-2);
	if (i == 4)
		(*data)->textures->floor = itorgb(
				ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	if (i == 5)
		(*data)->textures->ceiling = itorgb(
				ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	return (0);
}

int	init_texture(t_c3_data **data, char *line)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(line + 3);
	if (texture == NULL)
		return (-2);
	(*data)->textures->east = mlx_texture_to_image(
			(*data)->mlx, texture);
	if ((*data)->textures->east == NULL)
		return (-2);
	return (0);
}

void	free_data(t_c3_data *data)
{
	ft_free_strtab(data->map);
	free(data->player);
	free(data->textures);
	free(data);
}

t_c3_data	*data_init(void)
{
	t_c3_data	*data;

	data = malloc(sizeof(t_c3_data));
	data->textures = malloc(sizeof(t_textures));
	data->player = malloc(sizeof(t_player));
	return (data);
}
