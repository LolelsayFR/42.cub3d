/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:11:24 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/29 13:32:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.define.h"

unsigned long	create_rgb(t_rgb rgb)
{
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}

unsigned long	darker_rgb(unsigned long hexrgb, double divider)
{
	double	r;
	double	g;
	double	b;

	divider *= 0.7;
	if ((int)divider == 0)
		return (hexrgb);
	r = (((hexrgb >> 16) & 0xFF) / divider);
	g = (((hexrgb >> 8) & 0xFF) / divider);
	b = (((hexrgb) & 0xFF) / divider);
	return ((((int)r & 0xff) << 16) + (((int)g & 0xff) << 8) + ((int)b & 0xff));
}
