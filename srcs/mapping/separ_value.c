/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:43:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/26 15:24:20 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

char	**verif_inmap(char **whole_map, int emplacement)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = ft_strtabdup(&whole_map[emplacement]);
	ft_free_strtab(whole_map);
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\n')
		{
			if (map[y][x] != ' ')
				break ;
			x++;
		}
		if (x == (int)ft_strlen(map[y]) - 1
			&& finds_other_space(map[y + 1]) != 0)
			return (ft_free_strtab(map), NULL);
		y++;
	}
	return (map);
}

static int	do_texture_3(t_c3_data **data, char *line, int *i)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return ((*i)++, init_rgb(data, line, 0));
	if (ft_strncmp(line, "C ", 2) == 0)
		return ((*i)++, init_rgb(data, line, 1));
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
	if (ft_strncmp(line, "DO ", 3) == 0)
		return ((*i)++, init_texture(data,
				&(*data)->textures->door, line));
	return (do_texture_3(data, line, i));
}

static int	do_texture(t_c3_data **data, char *line, int *ret)
{
	static int	i = 0;

	if (i == 6)
		*ret = -1;
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (i++, init_texture(data,
				&(*data)->textures->north, line));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (i++, init_texture(data,
				&(*data)->textures->south, line));
	*ret = do_texture_2(data, line, &i);
	if (i == 7 && *ret != -2)
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
		if (finds_other_space(info[i]) != 0)
			if (do_texture(data, info[i], &ret) == -2)
				return (ft_printfd(2, ERROR WRONG_ID), -1);
		if (i++ > 0 && ret == -1)
			break ;
	}
	if (info[i] == NULL)
		return (ft_printfd(2, ERROR WRONG_ID), -1);
	while (info[i] != NULL && finds_other_space(info[i]) == 0)
		i++;
	if (info[i] == NULL)
		return (ft_printfd(2, ERROR NO_MAP), -1);
	(*data)->map = verif_inmap(info, i);
	if ((*data)->map == NULL)
		return (ft_printfd(2, ERROR DOUBLE_MAP), -1);
	return (0);
}
