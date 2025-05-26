/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:55:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/25 16:15:23 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.define.h"

//Function base https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	img_put_bg(t_img *img, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			img_pix_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	img_put_dual_bg(t_img *img, int sky, int floor, t_c3_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			if (y > (HEIGHT / 2) + MOUSESPEED_Y * data->v_view)
				img_pix_put(img, x, y, floor);
			else
				img_pix_put(img, x, y, sky);
			x++;
		}
		y++;
	}
}

t_img	*img_new(int size_x, int size_y, t_c3_data *data)
{
	t_img	*n;

	n = mlx_new_image(data->mlx, size_x, size_y);
	n->data = mlx_get_data_addr(n, &n->bpp, &n->size_line, &n->format);
	return (n);
}
