/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_apply.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:39:15 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/25 17:27:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	texture_apply(t_img *img, int x, int y, t_ray ray)
{
	unsigned long	color;
	char			*pixel;
	int				imgx;
	int				imgy;

	imgx = ray.texture->width * x / WIDTH;
	imgy = (ray.texture->height * y / HEIGHT);
	if (ray.texture == NULL)
		return ;
	pixel = ray.texture->data
		+ (imgy * ray.texture->size_line + imgx * (ray.texture->bpp / 8));
	color = *(unsigned int *)pixel;
	img_pix_put(img, x, y, color);
}
