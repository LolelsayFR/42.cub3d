/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 16:55:01 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	main(int argc, char **argv)
{
	t_c3_data	data;

	(void)argv;
	if (argc != 2)
		return (1);
	// data = mapping(argv);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		game_close(&data, 2);
	data.is_running = true;
	game_start(&data);
	return (0);
}
void	game_close(t_c3_data *data, int exit_status)
{
	data->is_running = false;
	ft_alist_free();
	//free_data(&data);
	if (exit_status == 2)
		ft_printfd(2, LANG_E, LANG_E_MALLOC);
	exit(exit_status);
}
