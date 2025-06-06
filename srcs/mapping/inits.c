/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:58:48 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/06 16:32:42 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static void	add_rgb(t_rgb *rgb, char *temp)
{
	static int	i = 0;

	if (i == 0)
		rgb->r = ft_atoi(temp);
	else if (i == 1)
		rgb->g = ft_atoi(temp);
	else if (i == 2)
		rgb->b = ft_atoi(temp);
	free(temp);
	i++;
	if (i == 3)
		i = 0;
}

static int	go_next_col(char *line, int *i, int j)
{
	if (j != 0)
	{
		while (line[*i] == ' ')
			(*i)++;
		if (line[*i] != ',')
			return (-1);
		(*i)++;
	}
	return (0);
}

int	do_rgb(t_rgb *rgb, char *line)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	j = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (go_next_col(line, &i, j) == -1)
			return (-1);
		while (line[i] == ' ')
			i++;
		if (!ft_isdigit(line[i]))
			return (-1);
		j = 0;
		while (ft_isdigit(line[i + j]))
			j++;
		temp = ft_substr(line, i, j);
		if (ft_atoi(temp) < 0 || ft_atoi(temp) > 255
			|| intlen(ft_atoi(temp)) > 3)
			return (free(temp), -1);
		add_rgb(rgb, temp);
		i += j;
	}
	return (0);
}

int	init_rgb(t_c3_data **data, char *line, int i)
{
	static int	f = 0;
	static int	c = 0;
	char		**temp;

	temp = ft_split(line + 2, ',');
	if (ft_tablen(temp) != 3)
		return (ft_free_strtab(temp), -3);
	if (i == 0)
	{
		if (f == 1)
			return (ft_free_strtab(temp), -2);
		if (do_rgb(&((*data)->textures->floor), line) == -1)
			return (ft_free_strtab(temp), -3);
		f = 1;
	}
	if (i == 1)
	{
		if (c == 1)
			return (ft_free_strtab(temp), -2);
		if (do_rgb(&((*data)->textures->ceiling), line) == -1)
			return (ft_free_strtab(temp), -3);
		c = 1;
	}
	return (ft_free_strtab(temp), 0);
}

int	init_texture(t_c3_data **data, t_img **img, char *line)
{
	int			i;
	static int	x;
	static int	y;

	if ((*img) != NULL)
		return (-2);
	i = 3;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (-2);
	line[ft_strlen(line) - 1] = '\0';
	(*img) = mlx_xpm_file_to_image((*data)->mlx, &line[i], &x, &y);
	if ((*img) == NULL)
		return (-4);
	return (0);
}
