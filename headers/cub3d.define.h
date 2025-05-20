/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 14:55:56 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# define WIDTH			1920
# define HEIGHT			1000
# define MINIMAP_TILE	20

# define RED_PIXEL		0xFF0000
# define DARKRED_PIXEL	0x660000
# define GREEN_PIXEL	0x00FF00
# define WHITE_PIXEL	0xFFFFFF
# define GREY_PIXEL		0x424242
# define BLACK_PIXEL	0x000000
# define YELLOW_PIXEL	0xF0F000
# define BLUE_PIXEL		0x000FF0

/* ************************************************************************** */
/*  All includes                                                              */
/* ************************************************************************** */

# include <math.h>
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
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../submodules/minilibx-linux/mlx.h"
# include "../submodules/minilibx-linux/mlx_int.h"
# include "../submodules/42.libft/libft.h"

/* ************************************************************************** */
/*  Typedef of struct                                                         */
/* ************************************************************************** */

typedef struct s_textures
{
	t_img	*map_base;
	t_img	*north;
	t_img	*south;
	t_img	*west;
	t_img	*east;
	t_rgb	floor;
	t_rgb	ceiling;
}	t_textures;

typedef struct s_control
{
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	sprint;
}	t_control;

typedef struct s_player
{
	int			pos[2];
	int			to_move[2];
	t_control	*control;
}	t_player;

typedef struct s_c3_data
{
	char		**map;
	bool		is_running;
	int			map_size[2];
	int			spawn[2];
	t_player	*player;
	t_textures	*textures;
	void		*mlx;
	void		*win;
	int			exit_status;
}	t_c3_data;

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
