/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:43:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 12:41:48 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static int	do_texture_2(t_c3_data **data, char *line, int i)
{
	mlx_texture_t	*texture;

	if (i == 2)
	{
		if (ft_strncmp(line, "WE ", 3) == 0)
		{
			texture = mlx_load_png(line + 3);
			(*data)->textures->east = mlx_texture_to_image((*data)->mlx, texture);
		}
		else
			return (-1);
	}
	else if (i == 3)
	{
		if (ft_strncmp(line, "EA ", 3) == 0)
		{
			texture = mlx_load_png(line + 3);
			(*data)->textures->east = mlx_texture_to_image((*data)->mlx, texture);
		}
		else
			return (-1);
	}
	else if (i >= 4)
		return (-1);
	return (0);
}

static int	do_texture(t_c3_data **data, char *line)
{
	mlx_texture_t	*texture;
	static int	i = 0;
	
	if (i == 0)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			texture = mlx_load_png(line + 3);
			(*data)->textures->east = mlx_texture_to_image((*data)->mlx, texture);
		}
		else
			return (-1);
	}
	else if (i == 1)
	{
		if (ft_strncmp(line, "SO ", 3) == 0)
		{
			texture = mlx_load_png(line + 3);
			(*data)->textures->east = mlx_texture_to_image((*data)->mlx, texture);
		}
		else
			return (-1);
	}
	i++;
	return (do_texture_2(data, line, i - 1));
}

int	separ_value(t_c3_data **data)
{
	int		i;
	char	**info;

	i = 0;
	info = (*data)->map;
	while (info[i] != NULL)
	{
		if (ft_strncmp(info[i], "\n", 1) == 0)
			if (do_texture(data, info[i]) == -1)
				break ;
		i++;
	}
	if (info[i] == NULL)
		return (-1);
	while (ft_strncmp(info[i], "\n", 1) == 0)
		i++;
	while (info[i] != NULL)
	{
		i++;
	}
	return (0);
}
