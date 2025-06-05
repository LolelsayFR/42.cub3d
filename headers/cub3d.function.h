/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/04 02:55:35 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FUNCTION_H
# define CUB3D_FUNCTION_H

# include "cub3d.define.h"
# include "cub3d.lang.h"

/* ************************************************************************** */
/*  Minishell main functions                                                  */
/* ************************************************************************** */

//Main Function
void			game_start(t_c3_data *data);
t_c3_data		*data_init(void);
t_c3_data		*mapping(char **argv);

//Free and exit
void			game_close(t_c3_data *data);
void			free_data(t_c3_data *data);
void			free_data_no_img(t_c3_data *data);

//Executing handler
int				handle_input_keyrelease(int key, t_c3_data *data);
int				handle_input(int key, t_c3_data *data);
int				handle_mouse(t_c3_data *data);
int				handle_mouse_click(int button, int x, int y, t_c3_data *data);

//Raycasting
void			ray_colider(t_c3_data *data, t_pos pos, int x, double angle);
void			raycasting(t_c3_data *data, t_pos pos, double angle);
unsigned long	texture_get_pix(int y, t_ray ray);
void			put_buffer(t_c3_data *data, t_ray *ray, int x);
void			door_clock(t_c3_data *data, t_pos pos);

//Img
void			create_minimap_img(t_c3_data *data);
t_img			*img_new(int size_x, int size_y, t_c3_data *data);
void			img_pp(t_img *img, int x, int y, int color);
void			img_put_bg(t_img *img, int color);
void			draw_map(t_c3_data *data, int x, int y);

//Player
bool			player_init(t_c3_data *data);
void			player_move(t_c3_data *data);

void			door_using(t_c3_data *data);

//Parsing
int				ext_is_correct(char *map);
int				charset_is_correct(t_c3_data *data);
int				convert_map(t_c3_data **data, char *map_file);
int				separ_value(t_c3_data **data);
int				init_texture(t_c3_data **data, t_img **img, char *line);
int				is_not_walled(t_c3_data *data);
int				finds_next_value(t_c3_data *data, int x, int y, int max);
int				finds_other_space(char *line);
void			find_max(char **map, int *x, int *y);
void			map_size(t_c3_data *data);
void			doors_stocking(t_c3_data **data);

//Utils
t_door			*get_door_data(t_c3_data *data, t_pos pos);
unsigned long	darker_rgb(unsigned long rgb, double divider);
void			img_put_dual_bg(t_img *img, int sky, int floor, t_c3_data *d);
int				mouse_hide(t_xvar *xvar, t_win_list *win, t_c3_data *data);
int				mouse_show(t_xvar *xvar, t_win_list *win, t_c3_data *data);
int				mouse_move(t_xvar *xvar, t_win_list *win, int x, int y);
unsigned long	c_rgb(t_rgb rgb);
t_pos			pos_to_map_pos(double x, double y);
t_trigo			trigo(double *angle, double x, double y);
void			raytrigo(t_ray *ray, double dist, t_pos pos);
int				ft_tablen(char **tab);
void			print_tab(char **tab);
char			**lst_to_tab(t_list *lst);
char			**lst_to_map(t_list *lst);
int				init_rgb(t_c3_data **data, char *line, int i);

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
