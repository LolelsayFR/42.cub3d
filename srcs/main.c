/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 19:59:37 by emaillet         ###   ########.fr       */
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
	game_start(data);
	free_data(data);
	return (0);
}

void	game_close(t_c3_data *data)
{
	int	status;

	if (data->exit_status == 2)
		ft_printfd(2, LANG_E, LANG_E_MALLOC);
	data->is_running = false;
	status = data->exit_status;
	ft_alist_free();
	mlx_destroy_image(data->mlx, data->textures->map_base);
	mlx_destroy_image(data->mlx, data->textures->map_player);
	mlx_destroy_image(data->mlx, data->textures->map_pangle);
	mlx_destroy_image(data->mlx, data->textures->floor_t);
	mlx_destroy_image(data->mlx, data->textures->ceiling_t);
	mlx_do_key_autorepeaton(data->mlx);
	free_data(data);
	exit(status);
}
