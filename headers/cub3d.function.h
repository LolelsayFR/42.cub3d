/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/19 13:28:20 by artgirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FUNCTION_H
# define CUB3D_FUNCTION_H

# include "cub3d.define.h"
# include "cub3d.lang.h"

/* ************************************************************************** */
/*  Minishell main functions                                                  */
/* ************************************************************************** */

int			ft_tablen(char **tab);
int			init_rgb(t_c3_data **data, char *line, int i);
int			ext_is_correct(char *map);
int			charset_is_correct(char **map);
int			convert_map(t_c3_data **data, char *map_file);
int			separ_value(t_c3_data **data);
int			init_texture(t_c3_data **data, char *line);
void		free_data(t_c3_data *data);
void		print_tab(char **tab);
char		**lst_to_tab(t_list *lst);
t_c3_data	*data_init(void);
t_c3_data	*mapping(char **argv);

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
