/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:40:46 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/20 12:21:20 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	init_rgb(t_c3_data **data, char *line, int i)
{
	char	**temp;

	temp = ft_split(line + 2, ',');
	if (ft_tablen(temp) != 3)
		return (ft_free_strtab(temp), -2);
	if (i == 4)
		(*data)->textures->floor = itorgb(
				ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	if (i == 5)
		(*data)->textures->ceiling = itorgb(
				ft_atoi(temp[0]), ft_atoi(temp[1]), ft_atoi(temp[2]));
	ft_free_strtab(temp);
	return (0);
}

int	init_texture(t_c3_data **data, t_img **img, char *line)
{
	static int	x;
	static int	y;

	line[ft_strlen(line) - 1] = '\0';
	(*img) = mlx_xpm_file_to_image((*data)->mlx, line + 3, &x, &y);
	if ((*img) == NULL)
		return (-2);
	return (0);
}

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
