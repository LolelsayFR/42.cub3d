/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:11:24 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/21 16:17:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.define.h"

unsigned long	create_rgb(t_rgb rgb)
{
	return (((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff));
}
