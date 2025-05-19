/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 17:28:26 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	main(int argc, char **argv)
{
	t_c3_data	*data;

	if (argc != 2)
		return (1);
	data = mapping(argv);
	if (data == NULL)
		return (1);
	//game_start(data);
	ft_alist_free();
	free_data(data);
	return (0);
}
