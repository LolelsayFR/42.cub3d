/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artgirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 00:53:42 by artgirar          #+#    #+#             */
/*   Updated: 2025/06/06 16:33:09 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.function.h"

void	assign_error(int ret_val)
{
	if (ret_val == -2)
		ft_printfd(2, ERROR WRONG_ID);
	else if (ret_val == -3)
		ft_printfd(2, ERROR BAD_ASSIGN);
	else if (ret_val == -4)
		ft_printfd(2, ERROR BAD_PATH);
}
