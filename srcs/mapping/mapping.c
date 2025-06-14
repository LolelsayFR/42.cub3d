/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:36:53 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/02 18:21:41 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

t_c3_data	*mapping(char **argv)
{
	t_c3_data	*data;

	if (ext_is_correct(argv[1]) == -1)
		return (NULL);
	data = data_init();
	if (data == NULL)
		return (free_data(data), NULL);
	if (convert_map(&data, argv[1]) == -1)
		return (free_data(data), NULL);
	if (separ_value(&data) == -1)
		return (free_data(data), NULL);
	if (charset_is_correct(data) == -1)
		return (free_data(data), NULL);
	if (is_not_walled(data) == -1)
		return (free_data(data), NULL);
	doors_stocking(&data);
	print_tab(data->map);
	return (data);
}
