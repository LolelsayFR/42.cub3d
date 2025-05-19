/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 19:34:38 by artgirar         ###   ########.fr       */
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
void		game_close(t_c3_data *data);

//Executing
void		game_start(t_c3_data *data);

int			ft_tablen(char **tab);
int			init_rgb(t_c3_data **data, char *line, int i);
int			ext_is_correct(char *map);
int			charset_is_correct(t_c3_data *data);
int			convert_map(t_c3_data **data, char *map_file);
int			separ_value(t_c3_data **data);
int			init_texture(t_c3_data **data, t_img **img, char *line);
int			is_not_walled(t_c3_data *data);
int			finds_next_value(t_c3_data *data, int x, int y);
void		find_max(char **map, int *x, int *y);
void		free_data(t_c3_data *data);
void		free_data_no_img(t_c3_data *data);
void		print_tab(char **tab);
char		**lst_to_tab(t_list *lst);
t_c3_data	*data_init(void);
t_c3_data	*mapping(char **argv);

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
