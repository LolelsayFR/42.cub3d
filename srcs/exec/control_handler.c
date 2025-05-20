/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:28:05 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 20:32:47 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

int	handle_input(int keysym, t_c3_data *data)
{
	if (keysym == XK_Escape)
		return (game_close(data), 0);
	else if (keysym == XK_d || keysym == XK_D)
		data->player->control->right = true;
	else if (keysym == XK_a || keysym == XK_A)
		data->player->control->left = true;
	else if (keysym == XK_w || keysym == XK_W)
		data->player->control->up = true;
	else if (keysym == XK_s || keysym == XK_S)
		data->player->control->down = true;
	else if (keysym == XK_Left)
		data->player->control->angle--;
	else if (keysym == XK_Right)
		data->player->control->angle++;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->player->control->sprint = true;
	return (0);
}

int	handle_input_keyrelease(int keysym, t_c3_data *data)
{
	if (keysym == XK_d || keysym == XK_D)
		data->player->control->right = false;
	else if (keysym == XK_a || keysym == XK_A)
		data->player->control->left = false;
	else if (keysym == XK_w || keysym == XK_W)
		data->player->control->up = false;
	else if (keysym == XK_s || keysym == XK_S)
		data->player->control->down = false;
	else if (keysym == XK_Shift_L || keysym == XK_Shift_R)
		data->player->control->sprint = false;
	return (0);
}
