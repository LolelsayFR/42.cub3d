/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 23:58:28 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# if POTATO
#  define WIDTH			213
#  define HEIGHT		120
#  define FOV			40
#  define DIST_FACTOR	20
#  define RAY_DIVIDER	6
#  define RAY_PRECISION	0.2
#  define RENDER_DIST	5
#  define DOOR_DIST		1
#  define MINIMAP_SIZE	0
# else
#  define WIDTH			1280
#  define HEIGHT		720
#  define FOV			90
#  define DIST_FACTOR	80
#  define RAY_DIVIDER	4
#  define RAY_PRECISION	0.015
#  define RENDER_DIST	30
#  define DOOR_DIST		10
#  define MINIMAP_SIZE	200
# endif
# define TILE_SIZE		12
# define PLAYER_SIZE	4
# define FPS			120
# define USE_RANGE		1
# define WALKSPEED		2
# define RUNSPEED		5
# define VIEWSPEED		6
# define MOUSESPEED_X	0.15
# define MOUSESPEED_Y	3
# define N_PI			3.1415
# define RAY_CORRECTION	0.2
# define HITBOX			0.15

# define C_N_WALL		0x00FF00
# define C_S_WALL		0xFF0000
# define C_E_WALL		0x000FF0
# define C_W_WALL		0xF0F000
# define C_DOORS		0x424242
# define C_ODOORS		0xEEEEEE

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
	t_img	*door;
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
	int		id;
}	t_trigo;

typedef struct s_ray
{
	double			angle;
	t_trigo			math;
	t_pos			pos;
	t_pos			old_pos;
	double			dist;
	double			exec_dist;
	unsigned long	color;
	t_img			*texture;
	double			wally;
	int				y_pix;	
	t_pos			save_pos;
	double			shift_up;
	unsigned long	buffer[HEIGHT];
}	t_ray;

typedef struct s_anim
{
	double	test;
}	t_anim;

typedef struct s_door
{
	t_pos	pos;
	double	anim;
	bool	open;
	bool	is_anim;
	bool	colide;
}	t_door;

typedef struct s_c3_data
{
	char		**map;
	char		**map_door_link;
	bool		is_running;
	bool		mouse;
	t_player	*player;
	t_textures	*textures;
	t_xvar		*mlx;
	t_win_list	*win;
	t_door		*doors;
	int			n_doors;
	int			v_view;
	int			map_size[2];
	int			exit_status;
	t_ray		ray;
	t_img		*frame;
	double		d_test;
}	t_c3_data;

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
