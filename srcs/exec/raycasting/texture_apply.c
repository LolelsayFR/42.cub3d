/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:39:15 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/30 17:32:12 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

inline static void	deshift(int *x, int *y, int rangex, int rangey)
{
	while (*x < 0)
		*x += rangex;
	if (*x >= rangex)
		*x = *x % rangex;
	while (*y < 0)
		*y += rangey;
	if (*y >= rangey)
		*y = *y % rangey;
}

void	texture_apply(t_img *img, int x, int y, t_ray ray)
{
	unsigned long	color;
	char			*pixel;
	int				imgx;
	int				imgy;

	imgx = 0;
	imgy = 0;
	if (ray.texture == NULL)
		return ;
	if ((int)ray.old_pos.y > (int)ray.pos.y)
		imgx = (ray.pos.x - 1) * ray.texture->width;
	else if ((int)ray.old_pos.y < (int)ray.pos.y)
		imgx = ray.texture->width - (ray.pos.x - 1) * ray.texture->width;
	else if ((int)ray.old_pos.x > (int)ray.pos.x)
		imgx = ray.texture->width - (ray.pos.y - 1) * ray.texture->width;
	else if ((int)ray.old_pos.x < (int)ray.pos.x)
		imgx = (ray.pos.y - 1) * ray.texture->width;
	if (ray.wally <= 0)
		return ;
	imgy = (ray.texture->height * (y - ray.y_pix)) / ray.wally;
	deshift(&imgx, &imgy, ray.texture->width, ray.texture->height);
	pixel = ray.texture->data + (imgy * ray.texture->size_line
			+ (imgx % ray.texture->width) * (ray.texture->bpp / 8));
	color = darker_rgb(*(unsigned long *)pixel, ray.dist);
	img_pp(img, x, y, color);
}