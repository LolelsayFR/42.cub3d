/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:43:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/20 13:53:59 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

char	**verif_inmap(char **emplacement_map)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = ft_strtabdup(emplacement_map);
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] != ' ')
				break ;
			x++;
		}
		if (x == (int)ft_strlen(map[y]) - 1)
			return (ft_free_strtab(map), NULL);
		y++;
	}
	return (map);
}

static int	do_texture_3(t_c3_data **data, char *line, int *i)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return ((*i)++, init_rgb(data, line, *i));
	if (ft_strncmp(line, "C ", 2) == 0)
		return ((*i)++, init_rgb(data, line, *i));
	return (-2);
}

static int	do_texture_2(t_c3_data **data, char *line, int *i)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
		return ((*i)++, init_texture(data,
			&(*data)->textures->west, line));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return ((*i)++, init_texture(data,
			&(*data)->textures->east, line));
	return (do_texture_3(data, line, i));
}

static int	do_texture(t_c3_data **data, char *line, int *ret)
{
	static int	i = 0;

	if (i == 5)
		*ret = -1;
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (i++, init_texture(data,
			&(*data)->textures->north, line));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (i++, init_texture(data,
			&(*data)->textures->south, line));
	*ret = do_texture_2(data, line, &i);
	if (i == 6)
		*ret = -1;
	return (*ret);
}

int	separ_value(t_c3_data **data)
{
	int		i;
	int		ret;
	char	**info;

	i = 0;
	ret = 0;
	info = (*data)->map;
	while (info[i] != NULL)
	{
		if (ft_strncmp(info[i], "\n", 1) != 0)
			if (do_texture(data, info[i], &ret) == -2)
				return (ft_printfd(2, ERROR WRONG_ID), -1);
		i++;
		if (ret == -1)
			break ;
	}
	if (info[i] == NULL)
		return (ft_printfd(2, ERROR WRONG_ID), -1);
	while (ft_strncmp(info[i], "\n", 1) == 0)
		i++;
	(*data)->map = verif_inmap(&info[i]);
	ft_free_strtab(info);
	if ((*data)->map == NULL)
		return (ft_printfd(2, ERROR DOUBLE_MAP), -1);
	return (0);
}
