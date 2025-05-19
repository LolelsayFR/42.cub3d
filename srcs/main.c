/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:12:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 10:34:26 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	handle_input(mlx_key_data_t keys, void *data)
{
	mlx_t		*mlx;
	t_c3_data	*d;

	d = data;
	mlx = d->mlx;
	if (keys.key == MLX_KEY_ESCAPE && keys.action == MLX_PRESS)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", keys.key);
		mlx_close_window(mlx);
	}
	ft_printf("The %d key has been pressed\n\n", keys.key);
}

int	game_start(t_c3_data *data)
{

	data->mlx = mlx_init(WIDTH, HEIGHT, "So cub3D", true);
	if (!data->mlx)
		return (0);
	mlx_key_hook(data->mlx, &handle_input, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_c3_data	*data;

	if (argc != 2)
		return (1);
	(void)argv;
	ft_alist_add_back(data = ft_calloc(1, sizeof(t_c3_data)));
	//data = mapping(argv);
	game_start(data);
	ft_alist_free();
	return (0);
}
