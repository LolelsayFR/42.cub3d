/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:39:15 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/27 09:32:07 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	texture_apply(t_img *img, int x, int y, t_ray ray)
{
	unsigned long	color;
	char			*pixel;
	int				imgx;
	int				imgy;

	if ((int)ray.old_pos.y > (int)ray.pos.y)
		imgx = (ray.pos.x - 1) * ray.texture->width;
	else if ((int)ray.old_pos.y < (int)ray.pos.y)
		imgx = ray.texture->width - (ray.pos.x - 1) * ray.texture->width;
	else if ((int)ray.old_pos.x > (int)ray.pos.x)
		imgx = ray.texture->width - (ray.pos.y - 1) * ray.texture->width;
	else if ((int)ray.old_pos.x < (int)ray.pos.x)
		imgx = (ray.pos.y - 1) * ray.texture->width;
	imgy = (ray.texture->height * (y - ray.y_pixel)) / ray.wally;
	if (ray.texture == NULL)
		return ;
	if (ray.wally <= 0 || imgy <= 0)
		return ;
	pixel = ray.texture->data + (imgy * ray.texture->size_line
			+ (imgx % ray.texture->width) * (ray.texture->bpp / 8));
	color = darker_rgb(*(unsigned long *)pixel, ray.dist);
	img_pix_put(img, x, y, color);
}
