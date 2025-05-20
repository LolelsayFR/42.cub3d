/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/20 17:31:12 by emaillet         ###   ########.fr       */
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
void		game_start(t_c3_data *data);
t_c3_data	*data_init(void);
t_c3_data	*mapping(char **argv);

//Free and exit
void		game_close(t_c3_data *data);
void		free_data(t_c3_data *data);
void		free_data_no_img(t_c3_data *data);

//Executing
int			handle_input_keyrelease(int keysym, t_c3_data *data);
int			handle_input(int keysym, t_c3_data *data);

//Img
void		create_minimap_img(t_c3_data *data);
t_img		*img_new(int size_x, int size_y, t_c3_data *data);
void		img_pix_put(t_img *img, int x, int y, int color);
void		img_put_background(t_img *img, int color);

//Player
bool		player_init(t_c3_data *data);

//Parsing
int			ext_is_correct(char *map);
int			charset_is_correct(t_c3_data *data);
int			convert_map(t_c3_data **data, char *map_file);
int			separ_value(t_c3_data **data);
int			init_texture(t_c3_data **data, t_img **img, char *line);
int			is_not_walled(t_c3_data *data);
int			finds_next_value(t_c3_data *data, int x, int y, int max);
int			finds_other_space(char *line);
void		find_max(char **map, int *x, int *y);
void		map_size(t_c3_data *data);

//Utils
int			ft_tablen(char **tab);
void		print_tab(char **tab);
char		**lst_to_tab(t_list *lst);
char		**lst_to_map(t_list *lst);
int			init_rgb(t_c3_data **data, char *line, int i);

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
