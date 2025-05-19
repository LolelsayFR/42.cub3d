/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.function.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:31:49 by emaillet          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/05/19 17:10:52 by emaillet         ###   ########.fr       */
=======
/*   Updated: 2025/05/19 17:05:30 by emaillet         ###   ########.fr       */
>>>>>>> Stashed changes
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
void		game_close(t_c3_data *data, int exit_status);

//Executing
void		game_start(t_c3_data *data);

int			ft_tablen(char **tab);
int			init_rgb(t_c3_data **data, char *line, int i);
int			ext_is_correct(char *map);
int			charset_is_correct(char **map);
int			convert_map(t_c3_data **data, char *map_file);
int			separ_value(t_c3_data **data);
int			init_texture(t_c3_data **data, t_img **img, char *line);
void		free_data(t_c3_data *data);
void		print_tab(char **tab);
char		**lst_to_tab(t_list *lst);
t_c3_data	*data_init(void);
t_c3_data	*mapping(char **argv);

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */

#endif
