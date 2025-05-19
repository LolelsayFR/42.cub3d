/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:08:23 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/20 00:02:25 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	convert_map(t_c3_data **data, char *map_file)
{
	int		fd;
	char	*temp;
	t_list	*map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	map = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		ft_lstadd_back(&map, ft_lstnew(ft_strdup(temp)));
		free(temp);
	}
	(*data)->map = lst_to_tab(map);
	ft_lstclear(&map, free);
	close(fd);
	return (0);
}
