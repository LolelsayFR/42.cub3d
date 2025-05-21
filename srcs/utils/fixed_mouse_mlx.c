/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_mouse_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:17:34 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 19:05:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

//https://github.com/42Paris/minilibx-linux/issues/48

int	mouse_move(t_xvar *xvar, t_win_list *win, int x, int y)
{
	XWarpPointer(xvar->display, None, win->window, 0, 0, 0, 0, x, y);
	return (0);
}

int	mouse_hide(t_xvar *xvar, t_win_list *win, t_c3_data *data)
{
	data->mouse = true;
	XFixesHideCursor(xvar->display, win->window);
	return (0);
}

int	mouse_show(t_xvar *xvar, t_win_list *win, t_c3_data *data)
{
	data->mouse = false;
	XFixesShowCursor(xvar->display, win->window);
	return (0);
}
