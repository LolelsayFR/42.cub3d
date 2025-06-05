/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:02:27 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/05 18:06:48 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	main(int argc, char **argv)
{
	t_c3_data	*data;

	if (argc == 1)
		return (ft_printfd(2, "Missing Map in Second Argument\n"), 1);
	else if (argc >= 3)
		return (ft_printfd(2, "Too Many Arguments Sent\n"), 1);
	data = mapping(argv);
	if (data == NULL)
		return (1);
	game_start(data);
	free_data(data);
	return (0);
}
