/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:36:53 by artgirar          #+#    #+#             */
/*   Updated: 2025/05/19 12:48:50 by artgirar         ###   ########.fr       */
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
		return (NULL);
	if (convert_map(&data, argv[1]) == -1)
		return (NULL);
	separ_value(&data);
	print_tab(data->map);
	return (data);
}
