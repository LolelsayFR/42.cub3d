/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_ulong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 03:17:48 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 03:18:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	*ft_memset_ulong(void *s, unsigned long c, size_t n)
{
	size_t			i;
	unsigned char	*set;

	set = s;
	i = 0;
	while (i < n)
	{
		set[i] = c;
		i++;
	}
	return (s);
}
