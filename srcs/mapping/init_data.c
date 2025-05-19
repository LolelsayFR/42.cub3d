/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:40:46 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 15:47:48 by artgirar         ###   ########.fr       */
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

int	init_texture(t_c3_data **data, t_img **img, char *line)
{
	int	x;
	int	y;

	(*img) = mlx_xpm_file_to_image((*data)->mlx, line + 3, &x, &y);
	if ((*img) == NULL)
		return (-2);
	return (0);
}

t_c3_data	*data_init(void)
{
	t_c3_data	*data;

	data = malloc(sizeof(t_c3_data));
	data->textures = malloc(sizeof(t_textures));
	data->player = malloc(sizeof(t_player));
	data->mlx = mlx_init();
	return (data);
}
