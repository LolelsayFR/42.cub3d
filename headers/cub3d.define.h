/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/25 16:29:02 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# define WIDTH			1920
# define HEIGHT			1000
# define MINIMAP_SIZE	200
# define MINIMAP_BG		210
# define TILE_SIZE		24
# define PLAYER_SIZE	4
# define FPS			60
# define WALKSPEED		1
# define RUNSPEED		2
# define VIEWSPEED		2
# define MOUSESPEED_X	0.05
# define MOUSESPEED_Y	6
# define N_PI			3.1415926535897931
# define RAY_DIVIDER	1
# define FOV			75
# define DIST_FACTOR	30
# define RAY_PRECISION	0.01

# define C_N_WALL		0x00FF00
# define C_S_WALL		0xFF0000
# define C_E_WALL		0x000FF0
# define C_W_WALL		0xF0F000

# define RED_PIXEL		0xFF0000
# define DARKRED_PIXEL	0x660000
# define GREEN_PIXEL	0x00FF00
# define WHITE_PIXEL	0xFFFFFF
# define GREY_PIXEL		0x424242
# define BLACK_PIXEL	0x000000
# define YELLOW_PIXEL	0xF0F000
# define BLUE_PIXEL		0x000FF0
# define CYAN_PIXEL		0X00FFF0

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
# include <X11/extensions/Xfixes.h>
# include "../submodules/minilibx-linux/mlx.h"
# include "../submodules/minilibx-linux/mlx_int.h"
# include "../submodules/42.libft/libft.h"

/* ************************************************************************** */
/*  Typedef of struct                                                         */
/* ************************************************************************** */

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_textures
{
	t_img	*map_base;
	t_img	*map_player;
	t_img	*map_pangle;
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
	bool	use;
	bool	turn_left;
	bool	turn_right;
	int		map;
}	t_control;

typedef struct s_player
{
	t_pos		pos;
	double		to_move;
	double		angle;
	int			fov;
	t_control	*control;
}	t_player;

typedef struct s_trigo
{
	double	opo;
	double	adj;
	double	hypo;
	double	angle_rad;
}	t_trigo;

typedef struct s_ray
{
	double			angle;
	t_trigo			math;
	t_pos			pos;
	t_pos			old_pos;
	double			dist;
	unsigned long	color;
	t_img			*texture;
}	t_ray;

typedef struct s_c3_data
{
	char		**map;
	bool		is_running;
	bool		mouse;
	t_player	*player;
	t_textures	*textures;
	t_xvar		*mlx;
	t_win_list	*win;
	int			v_view;
	int			map_size[2];
	int			exit_status;
	t_ray		ray[WIDTH];
	t_img		*frame;
}	t_c3_data;

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
