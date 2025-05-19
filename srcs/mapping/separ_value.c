/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:43:59 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 17:07:49 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

static int	do_texture_3(t_c3_data **data, char *line, int *i)
{
	if (*i == 4)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			return ((*i)++, init_rgb(data, line, *i));
	}
	else if (*i == 5)
	{
		if (ft_strncmp(line, "C ", 2) == 0)
			return ((*i)++, init_rgb(data, line, *i));
	}
	(*i)++;
	return (-1);
}

static int	do_texture_2(t_c3_data **data, char *line, int *i)
{
	if (*i == 2)
	{
		if (ft_strncmp(line, "WE ", 3) == 0)
			return ((*i)++, init_texture(data,
				&(*data)->textures->west, line));
	}
	else if (*i == 3)
	{
		if (ft_strncmp(line, "EA ", 3) == 0)
			return ((*i)++, init_texture(data,
				&(*data)->textures->east, line));
	}
	return (do_texture_3(data, line, i));
}

static int	do_texture(t_c3_data **data, char *line, int *ret)
{
	static int	i = 0;

	if (i == 0)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			return (i++, init_texture(data,
				&(*data)->textures->north, line));
	}
	else if (i == 1)
	{
		if (ft_strncmp(line, "SO ", 3) == 0)
			return (i++, init_texture(data,
				&(*data)->textures->south, line));
	}
	*ret = do_texture_2(data, line, &i);
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
				return (-1);
		if (ret == -1)
			break ;
		i++;
	}
	if (info[i] == NULL)
		return (-1);
	while (ft_strncmp(info[i], "\n", 1) == 0)
		i++;
	(*data)->map = ft_strtabdup(&info[i]);
	ft_free_strtab(info);
	return (0);
}
