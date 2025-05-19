/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 16:58:37 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# define WIDTH			1920
# define HEIGHT			1000

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
# include "../submodules/minilibx-linux/mlx.h"
# include "../submodules/minilibx-linux/mlx_int.h"
# include "../submodules/42.libft/libft.h"

/* ************************************************************************** */
/*  Typedef of struct                                                         */
/* ************************************************************************** */

typedef struct s_textures
{
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
	t_control	control;
}	t_player;

typedef struct s_c3_data
{
	char		**map;
	int			spawn[2];
	t_player	*player;
	t_textures	*textures;
	void		*mlx;
	void		*win;
	bool		is_running;
}	t_c3_data;


/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
