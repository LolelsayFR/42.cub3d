/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 10:30:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# define WIDTH			960
# define HEIGHT			540

/* ************************************************************************** */
/*  All includes                                                              */
/* ************************************************************************** */

# include <errno.h>
# include <string.h>
# include <stdint.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../submodules/MLX42/include/MLX42/MLX42.h"
# include "../submodules/42.libft/libft.h"

/* ************************************************************************** */
/*  Typedef of struct                                                         */
/* ************************************************************************** */

typedef struct s_textures
{
	mlx_image_t	*north;
	mlx_image_t	*south;
	mlx_image_t	*west;
	mlx_image_t	*east;
	t_rgb		floor;
	t_rgb		celling;
}	t_textures;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_c3_data
{
	char		**map;
	t_player	*player;
	t_textures	*textures;
	mlx_t		*mlx;
}	t_c3_data;

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
